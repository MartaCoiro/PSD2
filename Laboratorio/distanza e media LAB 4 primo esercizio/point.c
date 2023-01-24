#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "point.h"
struct point {
	float x;
	float y;
};

Point createPoint(float x, float y,int n){
	
	Point p = malloc(n*sizeof(struct point));
	p->x=x;
	p->y=y;
	return p;
}

float ascissa(Point p){
	return p->x;
}

float ordinata(Point p){
	return p->y;
}


float spostamento(Point p1,float a) {
	float s;
	
	s=p1->x + p1->y+a;
	
	return s;
}

float distanza(Point p1, Point p2){
	float dx, dy,d;
	dx=p1->x - p2->x;
	dy=p1->y - p2->y;
	d=sqrt((dx*dx) + (dy*dy));
	return d;
}

float centroide(float dist,int n) {
	float m;
	m=dist/n;
	return m;
}
	
