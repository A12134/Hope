/*Discarded class, the LOD functionality has been intergraded with the model class*/

/*
#ifndef LOD_MESH_H
#define LOD_MESH_H
#include "mesh.h"
#include "shaderProgram.h"


// three level LOD class

enum class LODLvl
{
	lvl_1,
	lvl_2,
	lvl_3,
	lvl_4,
	lvl_5
};

class LODmesh : private meshDummy
{
private:
	mesh * lvl_1_mesh;
	mesh * lvl_2_mesh;
	mesh * lvl_3_mesh;
	mesh * lvl_4_mesh;
	mesh * lvl_5_mesh;
	LODLvl currentLvl;

public:
	LODmesh(mesh * lvl1, mesh * lvl2, mesh * lvl3, mesh * lvl4, mesh* lvl5);
	LODmesh(mesh * lvl1, mesh * lvl2, mesh * lvl3, mesh * lvl4);
	LODmesh(mesh * lvl1, mesh * lvl2, mesh * lvl3);
	LODmesh(mesh * lvl1, mesh * lvl2);
	LODmesh(mesh * lvl1);
	~LODmesh();

	void render(shaderProgram* shaderSP, mat4 projection, mat4 view, mat4 model);

};
#endif*/

