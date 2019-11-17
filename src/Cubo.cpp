#include "Cubo.h"

void Cubo::GetInfo() {
	auto currentPos = this->getPosition();
	this->x = currentPos.x;
	this->y = currentPos.y;
    this->z = currentPos.z;
	this->width = this->getWidth();
	this->height = this->getHeight();
}

void Cubo::draw(int x, int y, int z, int w, int h, int screenW, int screenH) {
	GetInfo();
	ofSetColor(this->myColor);
	ofBoxPrimitive::draw();
}