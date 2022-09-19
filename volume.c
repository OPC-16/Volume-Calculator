/* ---- Volumes of Many Geometric figures ---- 
		Author >_ OPC 
*/

/*	Formulae
cube = a^3
cuboid = l*b*h
cylinder = pi*r*r*h
sphere = 4/3(pi*r^3)
cone = (pi*r*r*h)/3
tetrahedron = ((a^3)*sqrt(2))/12
pyramid (sq base) = (a*a*h)/3 ....a is side of sq base
hollow cylinder = pi*h(R^2 - r^2)
torus = (pi^2/4)(R+r)(R-r)^2
ellipsoid = (4*pi*a*b*c)/3 ....a,b,c are x,y,z intercepts
capsule = pi*r*r((4/3)*r + a)

 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"ascii_generator.h"

#define pi 3.142
float r,R,h,side,vol;

int options();
void cube();
void cuboid();
void cylinder();
void sphere();
void cone();
void tetrahedron();
void pyramid();
void holl_cylinder();
void torus();
void ellipsoid();
void capsule();
void history();

int main() {
	int input;
	char yes_no;

	system("clear");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	printf("\tWelcome to Volume Calculator\n");
	printf("+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/\n");
	system("sleep 1");

	while(1) {
		input = options();

		if(input == 1) 
			cube();
		else if(input == 2) 
			cuboid();
		else if(input == 3) 
			cylinder();
		else if(input == 4) 
			sphere();
		else if(input == 5) 
			cone();
		else if(input == 6) 
			tetrahedron();
		else if(input == 7) 
			pyramid();
		else if(input == 8) 
			holl_cylinder();
		else if(input == 9) 
			torus();
		else if(input == 10) 
			capsule();
		else if(input == 11) 
			ellipsoid(); 
		else if(input == 100) 
			history();

		scanf("%c",&yes_no);
		printf("\n Do You want to Continue? [y]es or [n]o  ");
		scanf("%c",&yes_no);

		if(yes_no == 'y' || yes_no == 'Y') {
			system("clear");
			system("sleep 1");
		}
		else {
			system("clear");
			FILE *fp = fopen("history.txt","w");
			fprintf(fp," ");
			ascii_generator(333);
			fclose(fp);
			return 0;
		}

	} //while-loop
} //main

int options() {
	int input;
	printf("\n\n\n\n Which Geometric Figure interests You?\n");
	system("sleep 0.8");
	printf("\tCube (press 1)\n\tCuboid (press 2)\n\tCylinder (press 3)\n");
	system("sleep 0.8");
	printf("\tSphere (press 4)\n\tCone (press 5)\n\tTetrahedron (press 6)\n");
	system("sleep 0.8");
	printf("\tPyramid (press 7)\n\tCylindrical Tube (press 8)\n\tTorus (press 9)\n");
	system("sleep 0.8");
	printf("\tCapsule (press 10)\n\tEllipsoid (press 11)\n\n\tShow History (press 100)\n");
	system("sleep 0.6");
	printf("\n Please enter Your Choice >_ ");
	scanf("%d",&input);
	return input;
} //options

void cube() {
	int cube_in;
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n\n");
	printf("  ======================");
	printf("\n\t  CUBE\n");
	printf("  ======================\n");
	ascii_generator(1);

	printf("\nFind Volume from side (press 1)\nFind side from Volume (press 2)\n");
	printf("\n Enter your choice >_ ");
	scanf("%d",&cube_in);

	if(cube_in == 1) {
		fprintf(fp, "\n\n--------\n| Cube |\n--------\n");
		printf("\n Enter side of Cube >_ ");
		scanf("%f",&side);
		printf("\n Volume is >_ %.2f\n",pow(side,3));
		fprintf(fp, "Side = %.2f\nVolume = %.2f",side,pow(side,3));

	}
	else if(cube_in == 2) {
		fprintf(fp, "\n\n--------\n| Cube |\n--------\n");
		printf("\n Enter Volume of cube >_ ");
		scanf("%f",&vol);
		printf("\n Side is >_ %.2f\n",cbrt(vol));
		fprintf(fp, "Volume = %.2f\nSide = %.2f",vol,cbrt(vol));
	}
	else {
		printf("\n Sorry you entered wrong choice :(\n");
	} //if-else
	fclose(fp);

	system("sleep 0.5");
	
} //cube

void cuboid() {
	float l,b,h;
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n\n");
	printf("    ======================");
	printf("\n\t    CUBOID\n");
	printf("    ======================\n");
	ascii_generator(2);

	printf("\n Enter Length >_ ");
	scanf("%f",&l);
	printf(" Enter Breadth >_ ");
	scanf("%f",&b);
	printf(" Enter Height >_ ");
	scanf("%f",&h);
	printf("\n Volume is >_ %.2f\n",l*h*b);

	fprintf(fp,"\n\n----------\n| Cuboid |\n----------\n");
	fprintf(fp,"Length = %.2f\nBreadth = %.2f\nHeight = %.2f\nVolume = %.2f",l,b,h,l*b*h);
	fclose(fp);
	system("sleep 0.5");
} //cuboid

void cylinder() {
	float vol;
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n");
	printf("   \t\t ======================");
	printf("\n\t\t\t CYLINDER\n");
	printf("   \t\t ======================\n");
	ascii_generator(3);
	
	printf("\n Enter Radius >_ ");
	scanf("%f",&r);
	printf(" Enter Height >_ ");
	scanf("%f",&h);

	vol = pi*r*r*h;
	printf("\n Volume is >_ %.2f\n",vol);
	fprintf(fp,"\n\n");

	fprintf(fp,"\n\n------------\n| Cylinder |\n------------\n");
	fprintf(fp,"Radius = %.2f\nHeight = %.2f\nVolume = %.2f",r,h,vol);
	fclose(fp);

	system("sleep 0.5");
} //cylinder

void sphere() {
	int sphere_in;
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n");
	printf("\t  ======================");
	printf("\n\t\t  SPHERE\n");
	printf("\t  ======================\n");
	ascii_generator(4);

	printf("\n Find Volume from radius (press 1)\nFind radius from Volume (press 2)\n");
	printf("\n Enter your choice >_ ");
	scanf("%d",&sphere_in);

	if(sphere_in == 1) {
		printf("\n Enter Radius >_ ");
		scanf("%f",&r);
		vol = (4*pi*pow(r,3))/3;
		printf("\n Volume is >_ %.2f\n",vol);

		fprintf(fp,"\n\n----------\n| Sphere |\n----------\n");
		fprintf(fp,"Radius = %.2f\nVolume = %.2f",r,vol);
		fclose(fp);

		system("sleep 0.5");
	}
	else if(sphere_in == 2) {
		printf("\n Enter Volume >_ ");
		scanf("%f",&vol);
		r = cbrt((3*vol)/(4*pi));
		printf("\n Radius is >_ %.2f\n",r);

		fprintf(fp,"\n\n----------\n| Sphere |\n----------\n");
		fprintf(fp,"Volume = %.2f\nRadius = %.2f",vol,r);
		fclose(fp);

		system("sleep 0.5");
	}
	else {
		printf("\n Sorry you entered wrong choice :(\n");
	} //if-else
	system("sleep 0.5");
} //sphere

void cone() {
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n\n");
	printf("\t    ======================");
	printf("\n\t\t    CONE\n");
	printf("\t    ======================\n");
	ascii_generator(5);

	printf("\n Enter Radius >_ ");
	scanf("%f",&r);
	printf(" Enter Height >_ ");
	scanf("%f",&h);
	vol = (pi*r*r*h)/3;
	printf("\n Volume is >_ %.2f\n",vol);

	fprintf(fp,"\n\n--------\n| Cone |\n--------\n");
	fprintf(fp,"Radius = %.2f\nHeight = %.2f\nVolume = %.2f",r,h,vol);
	fclose(fp);

	system("sleep 0.5");
} //cone

void tetrahedron() {
	int tetra_in;
	double vol;
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n\n");
	printf("\t\t============================");
	printf("\n\t\t\tTETRAHEDRON\n");
	printf("\t\t============================\n");
	ascii_generator(6);

	printf("\n Find Volume from edge length (press 1)\nFind edge length from Volume (press 2)\n");
	printf("\n Enter your choice >_ ");
	scanf("%d",&tetra_in);

	if(tetra_in == 1) {
		printf("\n Enter edge length >_ ");
		scanf("%f",&side);
		vol = ((pow(side,3))*sqrt(2))/12;
		printf("\n Volume is >_ %f\n",vol);

		fprintf(fp,"\n\n---------------\n| Tetrahedron |\n---------------\n");
		fprintf(fp,"Side = %.2f\nVolume = %.2f",side,vol);
		fclose(fp);

		system("sleep 0.5");
	}
	else if(tetra_in == 2) {
		printf("\n Enter Volume >_ ");
		scanf("%lf",&vol);
		side = cbrt((12*vol)/sqrt(2));
		printf("\n Edge length is >_ %f\n",side);

		fprintf(fp,"\n\n---------------\n| Tetrahedron |\n---------------\n");
		fprintf(fp,"Volume = %.2f\nSide = %.2f",vol,side);
		fclose(fp);

		system("sleep 0.5");
	}
} //tetrahedron

void pyramid() {
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t========================");
	printf("\n\t\t\t\tPYRAMID\n");
	printf("\t\t\t========================\n");
	ascii_generator(7);

	printf("\n Enter Side of sqaure base >_ ");
	scanf("%f",&side);
	printf(" Enter Height >_ ");
	scanf("%f",&h);
	vol = (side*side*h)/3;
	printf("\n Volume is >_ %.3f\n",vol);

	fprintf(fp,"\n\n-----------\n| Pyramid |\n-----------\n");
	fprintf(fp,"Side = %.2f\nHeight = %.2f\nVolume = %.2f",side,h,vol);
	fclose(fp);

	system("sleep 0.5");

} //pyramid

void holl_cylinder() {
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n");
	printf("\t\t============================");
	printf("\n\t\t\tCYLINDRICAL TUBE\n");
	printf("\t\t============================\n");
	ascii_generator(8);
	
	printf("\nEnter Outer Radius >_ ");
	scanf("%f",&R);
	printf("Enter inner radius >_ ");
	scanf("%f",&r);
	printf("Enter Height >_ ");
	scanf("%f",&h);
	vol = (pi*h)*(R*R - r*r);
	printf("\nVolume is >_ %.3f\n",vol);

	fprintf(fp,"\n\n--------------------\n| Cylindrical Tube |\n--------------------\n");
	fprintf(fp,"Outer Radius = %.2f\nInner Radius = %.2f\nHeight = %.2f\nVolume = %.2f",R,r,h,vol);
	fclose(fp);

	system("sleep 0.5");
} //holl_cylinder


void torus() {
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n\n");
	printf("\t\t======================");
	printf("\n\t\t\tTORUS\n");
	printf("\t\t======================\n");
	ascii_generator(9);

	printf("\nEnter Outer Radius >_ ");
	scanf("%f",&R);
	printf("Enter Inner radius >_ ");
	scanf("%f",&r);
	vol = (pow(pi,2)/4)*(R+r)*(pow(R-r,2));
	printf("\nVolume is >_ %.4lf\n",vol);

	fprintf(fp,"\n\n---------\n| Torus |\n---------\n");
	fprintf(fp,"Outer Radius = %.2f\nInner radius = %.2f\nVolume = %.2f",R,r,vol);
	fclose(fp);

	system("sleep 0.5");
} //torus

void ellipsoid() {
	float a,b,c;
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n\n");
	printf("\t\t=========================");
	printf("\n\t\t\tELLIPSOID\n");
	printf("\t\t=========================\n");
	ascii_generator(11);

	printf("\n Enter X-intercept >_ ");
	scanf("%f",&a);
	printf(" Enter Y-intercept >_ ");
	scanf("%f",&b);
	printf(" Enter Z-intercept >_ ");
	scanf("%f",&c);
	vol = (4*pi*a*b*c)/3;
	printf("\n Volume is >_ %.4lf\n",vol);

	fprintf(fp,"\n\n-------------\n| Ellipsoid |\n-------------\n");
	fprintf(fp,"X-intercept = %.2f\nY-intercept = %.2f\nZ-intercept = %.2f\nVolume = %.2f",a,b,c,vol);
	fclose(fp);

	system("sleep 0.5");

} //ellipsoid

void capsule() {
	FILE *fp = fopen("history.txt","a");
	system("clear");
	printf("\n\n\n\n\n\n");
	printf("\t=========================");
	printf("\n\t\tCAPSULE\n");
	printf("\t=========================\n");
	ascii_generator(10);

	printf("\n Enter side length >_ ");
	scanf("%f",&side);
	printf(" Enter Radius >_ ");
	scanf("%f",&r);
	long double vo = pi*r*r*((4*r)/3 + side);
	printf("\n Volume is >_ %Lf\n",vo);

	fprintf(fp,"\n\n-----------\n| Capsule |\n-----------\n");
	fprintf(fp,"Side = %.2f\nRadius = %.2f\nVolume = %Lf",side,r,vo);
	fclose(fp);
	
	system("sleep 0.5");

} //capsule

void history() {
	FILE *fp = fopen("history.txt","r");
	char line;

	system("clear");
	while((line = getc(fp)) != EOF) {
		printf("%c",line);
	} //while-loop
	
} //history
