#ifdef _WIN32
#define GLEW_STATIC  
#endif

#include <main_includes.h>
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}
int main(int args, char* argv[]) {

	//#define TESTS_ON
#ifdef TESTS_ON
	//checks memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::cout << "Unit tests : " << __DATE__ << ' ' << __TIME__ << std::endl;
	ugraph_test::performAllTests();
	umap_test::performAllTests();
	dfs_test::testSearching();
#endif // TESTS_ON

	try {
		OpenGLApplication::initGLFW();

		SceneBuilder builder;
		builder.addSceneHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
		builder.setTitle("The Little Rocket - Space Graph Explorer");
		builder.setWidth(1200);
		builder.setHeight(800);
		builder.setFramebufferSizeCallback([](GLFWwindow*, int w, int h)->void {
			glViewport(0, 0, w, h);
		});

		Scene mainScene = builder.createScene();
		OpenGLApplication app;
		app.makeContextCurrent(mainScene);

		OpenGLApplication::initGLEW();

		UndirectedMap map(20, 20);
		UndirectedMapView mapView(map);
		mainScene.attachObjects(mapView.getObjects());

		LittleRocket rocket(LITTLE_ROCKET_MODEL_OBJ_PATH, LITTLE_ROCKET_MODEL_VERTEX_SHADER_PATH, LITTLE_ROCKET_MODEL_FRAGMENT_SHADER_PATH);
		mainScene.attachObjects(rocket.getObject());

		Camera camera({ { 0.f, 3.f, 9.f }, { 0.f, 0.f, -1.f }, { 0.f, 1.f, 0.f } });
		mainScene.attachCamera(std::make_shared<Camera>(camera));

		SceneController controller(&mainScene);
		controller.registerControlMethod(GLFW_KEY_ESCAPE, [&app]() {
			app.setApplicationShouldClose(GL_TRUE);
		});
		controller.registerControlMethod(GLFW_KEY_W, [&]() {
			auto cam = mainScene.getCamera();
			cam->moveForward(app.delta());
		});
		controller.registerControlMethod(GLFW_KEY_S, [&]() {
			auto cam = mainScene.getCamera();
			cam->moveBackward(app.delta());
		});
		controller.registerControlMethod(GLFW_KEY_A, [&]() {
			auto cam = mainScene.getCamera();
			cam->moveLeft(app.delta());
		});
		controller.registerControlMethod(GLFW_KEY_D, [&]() {
			auto cam = mainScene.getCamera();
			cam->moveRight(app.delta());
		});
		controller.registerControlMethod(GLFW_KEY_UP, [&]() {
			mainScene.getCamera()->increaseSpeed();
		});
		controller.registerControlMethod(GLFW_KEY_DOWN, [&]() {
			mainScene.getCamera()->decreaseSpeed();
		});   

		std::thread rocketMovement([&]() {
			glm::vec3 direction = mapView.getVertexPosition(3) - rocket.position();
			
			//rotation towards new direction
			//computes angle between vectors
			float dotProduct = glm::dot(direction, rocket.face());
			float denominator = glm::length(rocket.face()) * glm::length(direction);
			float angle = glm::degrees(acos(dotProduct / denominator));
			
			//determines whether we have left or right angle +1 right -1 left 
			short leftOrRight = sgn((glm::cross(direction, rocket.face())).y);

			float suppAngle = 0.f;
			while(abs(suppAngle) < abs(angle - 0.0005f) && leftOrRight != 0) {
				rocket.rotate(sgn(leftOrRight) * 0.005f, glm::vec3(0.f, 1.f, 0.f));
				//stops the thread
				if (app.shouldAppBeClosed()) {
					break;
				} 

				suppAngle += sgn(leftOrRight) * 0.005f;
			}

			//translation towards new direction

		});

		while (!app.shouldAppBeClosed()) {
			app.updateDeltaTime();
			controller.pollEvents();

			mainScene.clearColor({ 0.f, 0.f, 0.0f, .0f });
			mainScene.clearBuffers({ GL_COLOR_BUFFER_BIT, GL_DEPTH_BUFFER_BIT });
			mainScene.drawObjects();

			mainScene.swapBuffers();
		}

		rocketMovement.join();
	}
	catch (const std::runtime_error& ex) {
		std::cerr << ex.what();
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << '\n';
	}
	catch (...) {
		std::cerr << "Unknown exception\n";
	}

	return 0;
}