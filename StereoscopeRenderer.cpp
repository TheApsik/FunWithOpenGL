#include "StereoscopeRenderer.h"
#include<glm/gtc/type_ptr.hpp>

glm::mat4 StereoscopeRenderer::StereoProjection(float horizon, float _near, float _far, float _zero_plane, float _dist)
{
	float   _dx = horizon;
	float   _dy = horizon/getProportion();

	float   _clip_near = _dist + _zero_plane - _near;
	float   _clip_far = _dist + _zero_plane - _far;

	float  _n_over_d = _clip_near / _dist;

	float   _topw = _n_over_d * _dy / 2.0f;
	float   _bottomw = -_topw;
	float   _rightw = _n_over_d * (_dx / 2.0f - eyesDistance);
	float   _leftw = _n_over_d * (-_dx / 2.0f - eyesDistance);

	// Create a fustrum, and shift it off axis
	glm::mat4 proj = glm::frustum(_leftw, _rightw, _bottomw, _topw, _clip_near, _clip_far);

	proj = glm::translate(proj, glm::vec3(-eyesDistance, 0, 0));

	return proj;
}

void StereoscopeRenderer::placeCamera()
{
	glm::mat4 model = glm::mat4(1.0f);
	//model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	this->program.addUniformMatrix<>("model", 1, false, glm::value_ptr(model));

	glm::mat4 view = camera.getLookAt();
	this->program.addUniformMatrix<>("view", 1, false, glm::value_ptr(view));


	glm::mat4 projection = StereoProjection(19.0f, 12.99f, -100.0f, 0.0f, 13.0f);
	this->program.addUniformMatrix<>("projection", 1, false, glm::value_ptr(projection));
}

StereoscopeRenderer::StereoscopeRenderer(ShaderProgram& program, Camera& camera, DrawMethod method)
	:Renderer(program, camera, method), eyesDistance(-0.05f)
{}
