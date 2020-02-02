/*
 * File: P2.c
 * Copy: Copyright (c) 2020 Kaylee M. Orr
 * BlazerID: orr44
 * Vers: 2.0.0 01/31/2017 KMO - Added table 2.14 and 2.16
 * Vers: 1.0.0 01/27/2020 KMO - Original Coding
 * Desc: Uses user input to calculate properties of circles, rectangles, triangles, ellipses, and regular polygons
 */

 //using Visual Studios- prevents it from throwing error from being outdated (scanf_s works better)
#pragma warning(disable : 4996)

//preprogramming directives
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI acos(-1.0)


 // function prototypes
void get_circle_properties(void);
void get_rectangle_properties(void);
void get_triangle_properties(void);
void get_ellipse_properties(void);
void get_regular_polygon_properties(void);
/*
 *
 */
int main(int argc, char** argv) {
    void get_circle_properties(void);
	void get_rectangle_properties(void);
	void get_triangle_properties(void);
	void get_ellipse_properties(void);
	void get_regular_polygon_properties(void);


	//used to create individual .exe for each section

	get_circle_properties();
	printf("\n");
	get_rectangle_properties();
	printf("\n");
	get_triangle_properties();
	printf("\n");
	get_ellipse_properties();
	printf("\n");
	get_regular_polygon_properties();
	printf("\n");

	return (EXIT_SUCCESS);
}

void get_circle_properties(void)
{
	//initialize variables
	double r;
	double circumfrence;
	double area;

	//ask for user input
	printf("Enter the radius in inches:");
	scanf("%lf", &r);

	//calculate
	circumfrence = 2.0 * M_PI * r;
	area = M_PI * r * r;


	//output
	printf("Description                    Values\n");
	printf("=====================================\n");
	printf("radius:                      %.2f in\n", r);
	printf("perimeter:                   %.2f in\n", circumfrence);
	printf("area:                        %.2f in^2\n", area);
	printf("=====================================\n");
}

void get_rectangle_properties(void)
{
	//initialize variables
	double length;
	double width;
	double perimeter;
	double area;
	double diagonal;
	double aspect_ratio;
	double circumscribed_area;

	//get user input
	printf("Enter the length in inches:");
	scanf("%lf", &length);
	
	printf("Enter the width in inches:");
	scanf("%lf", &width);

	//calculate
	perimeter = 2.0 * length + 2.0 * width;
	area = length * width;
	diagonal = sqrt(length * length + width * width);
	aspect_ratio = width / length;
	circumscribed_area = min(length, width) * min(width, length) * M_PI;

	//output
	printf("Description                    Values\n");
	printf("=====================================\n");
	printf("length:                      %.2f in\n", length);
	printf("width:                       %.2f in\n", width);
	printf("perimeter:                   %.2f in\n", perimeter);
	printf("area:                        %.2f in^2\n", area);
	printf("diagonal:                    %.2f in\n", diagonal);
	printf("aspect ratio:                %.2f\n", aspect_ratio);
	printf("circumscribed area:          %.2f in^2\n", circumscribed_area);

}

void get_triangle_properties(void)
{
	//initialize variables
	double a;
	double b;
	double gamma;
	double c;
	double alpha;
	double beta;
	double perimeter;
	double p;
	double area;
	double in_radius;
	double inscribed_circle_area;
	double circumscribed_area;
	
	//user input
	printf("Enter the length of side a in inches:");
	scanf("%lf", &a);

	printf("Enter the length of side b in inches:");
	scanf("%lf", &b);

	printf("Enter the measurement of gamma in radians:");
	scanf("%lf", &gamma);

	//calculate
	c = sqrt(a * a + b * b - 2 * a * b * cos(gamma));
	alpha = acos((b * b + c * c - a * a) / (2 * b * c));
	beta = 1 - (cos(alpha)) * (cos(alpha)) - (cos(gamma)) * (cos(gamma));
	perimeter = a + b + c;
	p = perimeter / 2.0;  //half perimeter to calc area and in_radius
	area = sqrt(p * (p - a) * (p - b) * (p - c));
	in_radius = area / p; //used to calc inscribed circle area
	inscribed_circle_area = M_PI * in_radius * in_radius;
	circumscribed_area = (.5 * (a / alpha)) * (.5 * (a / alpha)) * M_PI;

	//output
	printf("Description                    Values\n");
	printf("=====================================\n");
	printf("a:                          %.2f in\n", a);
	printf("b:                          %.2f in\n", b);
	printf("gamma:                      %.2f radians\n", gamma);
	printf("c:                          %.2f in\n", c);
	printf("alpha:                      %.2f radians\n", alpha);
	printf("beta:                       %.2f radians\n", beta);
	printf("perimeter:                  %.2f in\n", perimeter);
	printf("area:                       %.2f in^2\n", area);
	printf("inscribed_circle_area:      %.2f in^2\n", inscribed_circle_area);
	printf("circumscribed_circle_area:  %.2f in^2\n", circumscribed_area);
	printf("=====================================\n");
}

void get_ellipse_properties(void)
{
	//initialize variables
	double minor;
	double major;
	double c;
	double e;
	double perimeter;
	double area;
	double inscribed_circle_area;
	double circumscribed_area;

	//user input
	printf("Enter in the minor axis length a in inches:");
	scanf("%lf", &minor);
	printf("Enter in the major axis length b in inches:");
	scanf("%lf", &major);

	//calculate
	c = sqrt(major * major - minor * minor);
	e = sqrt(1 - (minor / major) * (minor / major));
	perimeter = M_PI * (3 * (major + minor) - sqrt((3 * major + minor) * (major + 3 * minor)));
	area = M_PI * major * minor;
	inscribed_circle_area = M_PI * major * major;
	circumscribed_area = M_PI * minor * minor;

	//output
	printf("Description                    Values\n");
	printf("=====================================\n");
	printf("a:                               %.2f in\n", minor);
	printf("b:                               %.2f in\n", major);
	printf("c:                               %.2f in\n", c);
	printf("e:                               %.2f\n", e);
	printf("perimeter:                       %.2f in\n", perimeter);
	printf("area:                            %.2f in^2\n", area);
	printf("inscribed_circle_area:           %.2f in^2\n", inscribed_circle_area);
	printf("circumscribed_circle_area:       %.2f in^2\n", circumscribed_area);
	printf("=====================================\n");
}

void get_regular_polygon_properties(void)
{
	int n_i;
	int n;
	double s = 0;
	double a;
	double inRadius;
	double R;
	double theta;
	double perimeter;
	double area;
	double inscribed_circle_area;
	double circumscribed_area;
	
	//user input
	printf("Enter the number of sides n: ");
	scanf("%d", &n_i);
	n = n_i + 0.0; //wanted integer and double version
	
	printf("Enter the length of a side s in inches: ");
	scanf("%lf", &s);

	//calculate
	a = s / (2.0 * tan(M_PI / n));
	inRadius = a / cos(M_PI / n);
	R =inRadius * cos(M_PI / n);
	theta = (n - 2.0) * M_PI / n;
	perimeter = n * s;
	area = a * perimeter / 2.0;
	inscribed_circle_area = R * R * M_PI;
	circumscribed_area = R * R * M_PI;

	//output
	printf("Description                    Values\n");
	printf("=====================================\n");
	printf("n:                            %d\n", n_i);
	printf("s:                            %.2f in\n", s);
	printf("a:                            %.2f in\n", a);
	printf("R:                            %.2f in\n", R);
	printf("theta:                        %.2f radians\n", theta);
	printf("perimeter:                    %.2f in\n", perimeter);
	printf("area:                         %.2f in^2\n", area);
	printf("inscribed_circle_area:        %.2f in^2\n", inscribed_circle_area);
	printf("circumscribed_circle_area:    %.2f in^2\n", circumscribed_area);
	printf("=====================================\n");
}
