

#include "kan_lab5_functions.hpp"
// Function to call when sorting by Lnumber
bool compareLastName(const Student &a, const Student &b) {
  // Compares last names of two students
  std::string last_name_a = a.last_name;
  std::string last_name_b = b.last_name;
  return last_name_a < last_name_b;

}

// Helper Functions
void insertArray(Student* students, Student newStudent, int& count, int size) {

  if (count >= size) {
    // throw an exception
    throw std::out_of_range("Array is full");
  }
  int index = count;
  while (index > 0 && students[index - 1].l_number > newStudent.l_number) {
    students[index] = students[index - 1];
    index--;
  }
  // insert the new value at the correct index
  students[index] = newStudent;
  count++;

  std::cout << "Student data inserted into array at index " << index << std::endl;
}

// Main Functions
int getInteger(int min, int max) {
  // Get a number between min and max from the user
  int num;
  bool valid;
  do {
    std::cin >> num;
    std::cin.ignore(100, '\n');
    // set the input flag
    valid = true;
    // check if valid integer between min and max
    if (std::cin.fail() || num < min || num > max) {
      if (std::cin.fail()) {
        std::cout << "Invalid input, please try again" << std::endl;
        // clear error flags and flush input buffer
        std::cin.clear();
        std::cin.ignore(100, '\n');
      } else if (num < min || num > max) {
        std::cout << "Please choose a different number (must choose between " << min << " and " << max << ") ";
      }
      valid = false;
    }
  } while (!valid);
  return num;
}

std::string getString(std::string prompt) {
  // Get a string from the user
  std::string str;
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, str);
    if (!std::cin.fail()) {
      break;
    }
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Invalid input. Please try again." << std::endl;
  }
  return str;
}

std::string getLnumber() {
  // Get Lnumber from the user
  // The `Lnumber` will be in the format `L00xxxxxx`
  // where the x’s are replaced by digits and
  // in the range between 111111 and 999999
  std::string lNumber;
  bool valid = false;
  // Input validation
  do {
    std::cout << "Please enter an Lnumber (L00xxxxxx): ";
    std::cin >> lNumber;
    std::cin.ignore(100, '\n');
    // check if valid Lnumber
    if (std::cin.fail() || lNumber.length() != 9 || lNumber[0] != 'L' || lNumber[1] != '0' || lNumber[2] != '0') {
      if (std::cin.fail()) {
        std::cout << "Invalid input, please try again" << std::endl;
        // clear error flags and flush input buffer
        std::cin.clear();
        std::cin.ignore(100, '\n');
      } else if (lNumber.length() != 9 || lNumber[0] != 'L' || lNumber[1] != '0' || lNumber[2] != '0') {
        std::cout << "Please enter a valid Lnumber (L00xxxxxx): ";
      }
    }
    else {
      valid = true;
    }
  } while (!valid);

  return lNumber;
}

float getGPA() {
  // Get GPA from the user between 0.0 and 4.0
  float gpa;
  bool valid = false;
  do {
    std::cout << "GPA: ";
    std::cin >> gpa;
    std::cin.ignore(100, '\n');
    // check if valid GPA
    if (std::cin.fail() || gpa < 0.0 || gpa > 4.0) {
      if (std::cin.fail()) {
        std::cout << "Invalid input, please try again" << std::endl;
        // clear error flags and flush input buffer
        std::cin.clear();
        std::cin.ignore(100, '\n');
      } else if (gpa < 0.0 || gpa > 4.0) {
        std::cout << "Please enter a valid GPA (0.0 to 4.0): ";
      }
    }
    else {
      valid = true;
    }
  } while (!valid);
  return gpa;
}

Student *createArray(int numStudents) {
  // Create a dynamic array of students
  Student *students = new Student[numStudents];
  int count = 0;
  for (int i = 0; i < numStudents; i++) {
    //get an Lnumber, firstName, lastName, GPA
    std::string lnumber = getLnumber();
    std::string firstName = getString("First Name: ");
    std::string lastName = getString("Last Name: ");
    float gpa = getGPA();

    //create a struct with the data
    Student newStudent = {firstName, lastName, lnumber, gpa};

    //Using the Lnumber, insert the struct in the proper location in the array
    insertArray(students, newStudent, count, numStudents);

  }
  //Return the array when done

  return students;
}

void displayArrays(const Student *students, int count) {

  // display the arrays in columns `firstName`, `lastName`, `Lnumber`, and `GPA`
  std::cout << std::setw(10) << "First Name" << std::setw(10) << "Last Name" << std::setw(10) << "Lnumber" << std::setw(5) << "GPA" << std::endl;

  for (int i = 0; i < count; i++) {
    std::cout << std::setw(10) << students[i].first_name << std::setw(10) << students[i].last_name << std::setw(10) << students[i].l_number << std::setw(5) << students[i].gpa << std::endl;
  }
}

bool binSearch(Student *arr, int count, std::string value) {
  // perform a binary search
  // return true if the name is present, false otherwise
  int min = 0;
  int max = count - 1;
  bool found = false;
  while (max >= min && !found) {
    int mid = (min + max) / 2;
    if (arr[mid].last_name == value) {
      found = true;
    } else if (arr[mid].last_name > value) {
      max = mid - 1;
    } else {
      min = mid + 1;
    }
  }
  std::cout << "Searching for last name "<< value<<  std::endl;
  return found;

}



