/// @ref gtx_projection
/// @file glm/gtx/projection.inl

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType proj(genType const& x, genType const& normal)
	{
		return glm::dot(x, normal) / glm::dot(normal, normal) * normal;
	}
}//namespace glm
