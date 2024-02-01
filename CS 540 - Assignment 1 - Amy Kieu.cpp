// CS 540 - Assignment 1 - Amy Kieu.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib>
#include <limits> 	

// Functions outside of the main containing the shell commands using system() functions

void dir() {
	system("dir");	// list files in current directory
	std::cout << std::endl;
}

void cd() {
	system("cd");	// change directory, prints the working directory
	std::cout << std::endl;
}

void mkdir_rmdir() {
	int mkdir_output = system("mkdir new_folder"); // create a new directory
	if(mkdir_output == 0) {		// case for successful creation of a directory
		std::cout << "\"new_folder\" successfully created." << std::endl;
		std::cout << std::endl;
	}
	else if(mkdir_output != 0) {	// case for unsuccessful creation of a directory
		std::cout << "\"new_folder\" file not created because it already exists." << std::endl;
		std::cout << std::endl;
	}

	int rmdir_output = system("rmdir /s /q old_folder"); // removing a directory
	if(rmdir_output == 0) {		// case for succesful deletion of a directory
		std::cout << "\"old_folder\" successfully removed." << std::endl;
		std::cout << std::endl;
	}
	else if(rmdir_output != 0) {	// case for unsuccessful deletion of a directory
		std::cout << "\"old_folder\" file not removed because it was not found." << std::endl;
		std::cout << std::endl;
	}
}

void echo() {
	int return_msg = system("echo Hello World!"); // display a message
	if(return_msg == 0) {	// case for successful printing of the message
		std::cout << "Message printed successfully." << std::endl;
		std::cout << std::endl;
	}
	else if(return_msg != 0) {	// case for unsuccessful printing of the message
		std::cout << "Message not printed." << std::endl;
		std::cout << std::endl;
	}
}

void type() {
	int concatenate = system("type File1.txt File2.txt"); // concatenate and display content files
	std::cout << std::endl;
	std::cout << std::endl;
	if (concatenate == 0) {		// case for successful printing of content
		std::cout << "Concatenate successful and content files displayed." << std::endl;
		std::cout << std::endl;
	}
	else if (concatenate != 0) {	// case for unsuccessful printing of content
		std::cout << "Concatenate unsuccessful and content files could not be displayed." << std::endl;
		std::cout << std::endl;
	}
}

// Function for displaying the options for user to select

void MENU() {
	std::cout << "Please select an option: " << std::endl;
	std::cout << "[1] - List directory contents" << std::endl;
	std::cout << "[2] - Print working directory" << std::endl;
	std::cout << "[3] - Create a new directory" << std::endl;
	std::cout << "[4] - Display a message" << std::endl;
	std::cout << "[5] - Concatenate and display content of a file" << std::endl;
	std::cout << "[6] - EXIT" << std::endl;
	std::cout << std::endl;
}


int main()
{
	MENU();	// call menu prompt

	int user_input; // declaring variable

	while (true) { // while loop to allow user to continuously make an input
		std::cin >> user_input; // get user's selected option
		std::cout << std::endl;
	// call function according to user's selection
		if(user_input == 1) {
			dir();
		}
		else if(user_input == 2) {
			cd();
		}
		else if(user_input == 3) {
			mkdir_rmdir();
		}
		else if(user_input == 4) {
			echo();
		}
		else if(user_input == 5) {
			type();
		}
		else if(user_input == 6) {	
			break;  // exit out of loop
		}
		else {		// case for when the user enters values that are not available
			std::cin.clear();	// clear the error
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // remove the invalid input
			std::cout << "Invalid input. Try again." << std::endl;
			std::cout << std::endl;
		}
	// keep looping until user selects "6"
	}
}
