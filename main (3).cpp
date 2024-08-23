//JADE PINEDA
//SNHU
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Define the Course class
class Course {
public:
    std::string number;
    std::string title;
    std::vector<std::string> prerequisites;

    Course() {}

    Course(std::string courseNumber, std::string courseTitle, std::vector<std::string> prereqs) {
        number = courseNumber;
        title = courseTitle;
        prerequisites = prereqs;
    }
};

// Function to load courses from a file
std::unordered_map<std::string, Course> loadCoursesFromFile(const std::string& filename) {
    std::unordered_map<std::string, Course> courses;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return courses;
    }

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string courseNumber, courseTitle, prereq;
        std::vector<std::string> prerequisites;

        // Read the course number and title
        getline(ss, courseNumber, ',');
        getline(ss, courseTitle, ',');

        // Read all the prerequisites
        while (getline(ss, prereq, ',')) {
            if (!prereq.empty()) {
                prerequisites.push_back(prereq);
            }
        }

        // Create a Course object and add it to the hash table
        Course course(courseNumber, courseTitle, prerequisites);
        courses[courseNumber] = course;
    }

    file.close();
    return courses;
}

// Function to display the menu
void displayMenu() {
    std::cout << "1. Load Data Structure.\n";
    std::cout << "2. Print Course List.\n";
    std::cout << "3. Print Course.\n";
    std::cout << "9. Exit\n";
    std::cout << "What would you like to do? ";
}

// Function to load the course data
void loadData(std::unordered_map<std::string, Course>& courses) {
    // Automatically load the file from the specified path
    const std::string filename = "CS 300 ABCU_Advising_Program_Input.csv";
    courses = loadCoursesFromFile(filename);
    if (!courses.empty()) {
        std::cout << "Course data loaded successfully from " << filename << ".\n";
    } else {
        std::cout << "Failed to load course data from " << filename << ".\n";
    }
}

// Function to print the list of courses in alphanumeric order
void printCourseList(const std::unordered_map<std::string, Course>& courses) {
    if (courses.empty()) {
        std::cout << "No course data available. Please load the data first.\n";
        return;
    }

    // Convert the unordered_map to a vector for sorting
    std::vector<std::string> courseNumbers;

    for (const auto& pair : courses) {
        courseNumbers.push_back(pair.first);
    }

    // Sort the course numbers alphanumerically
    std::sort(courseNumbers.begin(), courseNumbers.end());

    // Print the sorted course list
    std::cout << "Here is a sample schedule:\n";
    for (const auto& number : courseNumbers) {
        std::cout << number << ", " << courses.at(number).title << "\n";
    }
}

// Function to print course information and prerequisites
void printCourseInfo(const std::unordered_map<std::string, Course>& courses) {
    if (courses.empty()) {
        std::cout << "No course data available. Please load the data first.\n";
        return;
    }

    std::string courseNumber;
    std::cout << "What course do you want to know about? ";
    std::cin >> courseNumber;

    // Convert input to uppercase for case-insensitive comparison
    std::transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);

    // Search for the course in the hash table
    if (courses.find(courseNumber) != courses.end()) {
        const Course& course = courses.at(courseNumber);
        std::cout << course.number << ", " << course.title << "\n";
        std::cout << "Prerequisites: ";
        if (course.prerequisites.empty()) {
            std::cout << "None\n";
        } else {
            for (size_t i = 0; i < course.prerequisites.size(); ++i) {
                if (i > 0) std::cout << ", ";
                std::cout << course.prerequisites[i];
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "Course " << courseNumber << " not found.\n";
    }
}

int main() {
    std::unordered_map<std::string, Course> courses;
    int choice = 0;

    while (choice != 9) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadData(courses);
                break;
            case 2:
                printCourseList(courses);
                break;
            case 3:
                printCourseInfo(courses);
                break;
            case 9:
                std::cout << "Thank you for using the course planner!\n";
                break;
            default:
                std::cout << choice << " is not a valid option.\n";
        }
    }

    return 0;
}
