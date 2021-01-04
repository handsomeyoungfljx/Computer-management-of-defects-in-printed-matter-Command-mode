#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;
#define pi 3.1415
const int SIZE = 60;

//struct Circle{
//	double center_x,center_y;
//	double radius;
//};

//struct Circle circles[1000];
//int cnt_circles=0;

class Shape
{
//	protected:
	private:
    	double center_x;
    	double center_y;
	public:
		/*将protected改为private要引用此语句*/
		Shape(double x=0,double y=0)
		{
			this->center_x=x;
			this->center_y=y;
		};
		/*将protected改为private要引用此语句*/
    	virtual double getArea()=0;
    	virtual void show()
		{
        	cout<<"("<<this->center_x<<","<<this->center_y<<") "<<"area:"<<this->getArea()<<endl;
    	}
};

class Rectangle: public Shape
{
	private:
    	double width;
    	double height;
	public:
    	Rectangle(double x,double y,double width,double height):Shape(x,y)
		{
//        	this->center_x=x;
//        	this->center_y=y;
        	this->width=width;
        	this->height=height;
    	}
    void show()
	{
        cout << "Rectangle : ";
        Shape::show();
    }
    double getArea()
	{
        return this->width*this->height;
    }

};

class Square: public Shape
{
	private:
    	double length;
	public:
    	Square(double x,double y,double length):Shape(x,y)	//将protected改为private要引用“:shape(x,y) ” 
		{
//        	this->center_x=x;
//        	this->center_y=y;
        	this->length=length; 
    	}
    	void show()
		{
        	cout << "Square : ";
        	Shape::show();
    	}
    	double getArea()
		{
    		return this->length*this->length;
    	}

};

class Circle:public Shape
{
	private:
    	double radius;
	public:
    	Circle(double x,double y,double radius):Shape(x,y)
		{
//        	this->center_x=x;
//        	this->center_y=y;
        	this->radius=radius;
    	}
    	void show()
		{
        	cout << "Circle : ";
        	Shape::show();
    	}
    	double getArea()
		{
        	return pi*this->radius*this->radius;
    	}
};

//void getArea(struct Circle *circle);
//void showCircle(struct Circle *circles);

int main()
{
	int m;
	int count=0;
	double areasum=0;
	double x,y,a,b;
    string type_R="Rectangle";
    string type_C="Circle";
    string type_S="Square";
    string type;
	
	char filename[SIZE];
	ifstream infile;		
	cout << "Enter name of data file: ";
	cin.getline(filename,SIZE);
	infile.open(filename);

	if (!infile.is_open())	
	{
		cout <<"Could not open the file" << filename << endl;
		cout <<"Program terminating.\n";
		exit(EXIT_FAILURE);
	}
//	ifstream inFile(filename,ios::in);
	
//	for (int i=0;;i++){
//		inFile >> circles[i].center_x >> circles[i].center_y >> circles[i].radius;
//		cnt_circles++;
//		if(inFile.eof())
//			break;
//		
		 
	
	
	infile >> m;
    cout <<m<<endl;
    Shape *shape[m];
    for(count;;count++)
	{
        infile>>type;
        if(type.compare(type_R)==0)
		{
            infile>>x>>y>>a>>b;
            Shape *sp=new Rectangle(x,y,a,b);
            shape[count]=sp;
        }
        else if(type.compare(type_C)==0)
		{
            infile>>x>>y>>a;
            Shape *sp=new Circle(x,y,a);
            shape[count]=sp;

        }
        else if(type.compare(type_S)==0)
		{
            infile>>x>>y>>a;
            Shape *sp=new Square(x,y,a);
            shape[count]=sp;

        }
        
        if(infile.eof())
            break;
    }
	
	
	
	
	
	
	
//	while (inFile.good())	
//	{
//		for (int i=0;i<1000;i++){
//			
//			inFile >> circles[0].center_x >> circles[0].center_y >> circles[0].radius;
//		}
//		
//		addCircle(double centrex,double centery,double radius);
		
//	}
	
	if(infile.eof())
		cout << "End of file reached.\n";
	else if (infile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
		
//	if(cnt_circles == 0)
//		cout << "No data processed\n";
//	else
//	{
//		for(int index =0 ;index<cnt_circles;index++){
////			showCircle(circles[index]); 
//		}
//	}
//	cout << circles[2].center_x <<" "<< circles[2].center_y << endl;
//	cout << cnt_circles << endl;
//	showCircle(circles);
//	getArea(circles);
//	inFile.close();	





	for(int i=0;i<count;i++)
	{
		shape[i]->show();
		areasum=areasum+shape[i]->getArea();	
	}
    cout << "area sum:"<<areasum << endl;

	
	infile.close();
	return 0;
}	


//void showCircle(struct Circle *circles){
//	for (int i=0;i<cnt_circles;i++)
//		{
//			cout << "Coordinates of circles: " << "(" << circles[i].center_x << "," << circles[i].center_y << ")"<< endl;
//			cout << "radius of circles: " << circles[i].radius<< endl;
//			cout << "area of this circles: " << circles[i].radius*circles[i].radius*3.14 << endl;
//			cout << endl;
//		}
////		cout << "area if all circles: " << double getArea(struct Circle circles) << endl;
//}
//
//void getArea(struct Circle *circles){
//	double Circle_Area=0;
//	for (int i=0;i<cnt_circles;i++){
//		Circle_Area=Circle_Area+circles[i].radius*circles[i].radius*3.14;
//	}
//	cout << Circle_Area << endl;
//}



