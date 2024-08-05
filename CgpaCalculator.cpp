#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;
//structure to hold course information
struct Course{
	string name;
	double grade;
	int creditHours;
	
};
//function to calculate gpa for a list of courses
double calculateGPA(const vector<Course>& courses){
	double totalPoints=0.0;
	int totalCreditHours=0;
	for (const auto& course : courses){
		totalPoints += course.grade*course.creditHours;
		totalCreditHours += course.creditHours;
		
	}
	if(totalCreditHours==0){
		return 0.0;
		
	}
	return totalPoints/totalCreditHours;
}
//function to handle user input for course details
void inputCourseDetails(vector<Course>& courses){
	int numCourses;
	cout<<"Enter number of courses:";
	cin>>numCourses;
	for(int i=0;i<numCourses;++i){
		Course course;
		cout<<"enter course namr: ";
		cin>>course.name;
		cout<<"enter grade (as points, e.g.,4.0 for A): ";
		cin>>course.grade;
		while(course.grade<0.0||course.grade>4.0){
			cout<<"invalid grade! enter grade (0.0 - 4.0): ";
			cin>>course.grade;
		}
		cout<<"enter credit hours: ";
		cin>>course.creditHours;
		while (course.creditHours<=0){
			cout<<"invalid credit hours! enter positive value: ";
			cin>>course.creditHours;
		}
		courses.push_back(course);
	}
}
//function ta calculate cgpa for multiple semesters
double calculateCGPA(const vector<vector<Course>>& semesters){
	double cumulativePoints=0.0;
	int cumulativeCreditHours=0;
	
	for (const auto& semester : semesters)
	{
		double semesterGPA = calculateGPA(semester);
		int semesterCreditHours=0;
		
		for(const auto& course : semester){
			semesterCreditHours += course.creditHours;
		}
		    cumulativePoints += semesterGPA * semesterCreditHours;
			cumulativeCreditHours += semesterCreditHours;
			
			
		}
		if (cumulativeCreditHours==0){
			return 0.0;
		}
		return cumulativePoints/cumulativeCreditHours;
		
		
	}
	//function to handle user input for multiple semesters
	void inputSemesterDetails(vector<vector<Course>>& semester){
		int numSemesters;
		cout<<"enter number of semesters: ";
		cin>>numSemesters;
		
		for(int i=0; i<numSemesters; ++i){
			vector<Course>semesterCourses;
			cout<<"Semester "<< i + 1 <<" : "<<endl;
			inputCourseDetails(semesterCourses);
			semesters.push_back(semesterCourses);
		}
		
	}
	int main(){
		vector<vector<Course>> semesters;
		cout<<"CGPA Calculator"<<endl;
		inputSemesterDetails(semesters);
		
		double cgpa = calculateCGPA(semesters);
		
		cout<<fixed<<setprecision(2);
		cout<<"cumulative GPA (CGPA): "<<cgpa<<endl;
		
		return 0;
	}

