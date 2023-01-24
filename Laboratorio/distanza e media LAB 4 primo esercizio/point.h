typedef struct point *Point;

Point createPoint(float x, float y,int n);
float ascissa(Point p);
float ordinata(Point p);
float spostamento(Point p1,float a); 
float distanza(Point p1, Point p2);
float centroide(float dist,int n);