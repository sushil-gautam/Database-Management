Driver Database Management System
1. Introduction<br>
With the increasing number of road accidents, the efficient management of driver data has become essential.
This project develops a Driver Database Management System using custom-built data structures without relying on STL.
The system ensures efficient storage, retrieval, and management of driver records while maintaining high performance.
3. Objectives
To design a structured system for storing driver information.
To implement efficient searching using hash tables.
To categorize drivers based on age, experience, and work type.
To retrieve newest and oldest drivers using stack and queue.
To handle large datasets efficiently.
4. Problem Statement
The city council requires a system to manage driver data including personal details, license information, and ticket history.
The system must support fast search operations and structured categorization.
It should also track drivers with recent licenses and elderly drivers with possible medical risks.
5. System Architecture
The system is based on Object-Oriented Programming principles.
It uses composition to integrate Address and Date classes inside the Driver class.
The Database class acts as the controller, integrating multiple data structures.
6. Data Structures Used
Hash Table: Used for fast searching of drivers by License ID with average O(1) complexity.
Linked List: Maintains ordered storage and supports flexible insertion.
Stack: Stores recently added drivers to retrieve newest drivers.
Queue: Stores drivers in order to retrieve oldest drivers.
7. Functional Requirements
Insert driver records into the database.
Search drivers using License ID.
Remove drivers from the system.
Display all driver records.
Retrieve N newest drivers.
Retrieve N oldest drivers.
8. Non-Functional Requirements
High performance and fast search operations.
Scalability to handle large datasets.
Error handling for invalid inputs.
Maintainability using modular design.
9. Implementation Details
The system reads driver data from a text file and parses it using string streams.
Safe conversion functions are used to prevent runtime errors.
Each driver is inserted into all relevant data structures simultaneously.




10. Program Flow
1. Load driver data from file.
2. Store data into hash table, linked list, stack, and queue.
3. Display menu options.
4. Execute operations based on user input.
5. Repeat until user exits.
10. Time Complexity Analysis
Insertion: O(1)
Search: O(1) average
Deletion: O(1) average
Display: O(n)
Stack/Queue operations: O(1)
11. Limitations
Removal operation does not update all data structures.
Hash table does not dynamically resize.
Age is not automatically calculated from date of birth.
12. Future Enhancements
Add graphical user interface (GUI).
Implement dynamic resizing of hash table.
Improve synchronization between data structures.
Add sorting and filtering features.
Implement database storage instead of text files.
	

13. Approach and Reason for Choosing Design
We began our project by designing and creating an algorithm. Throughout this algorithm, we outlined everything we would need within the project, and began planning the easiest and most organized way to accomplish that. We identified exactly what we needed the code to do, including inserting data, updating values, searching, and displaying results then built our design from there. 
We used classes to separate all of the different operations that our system had to perform. Creating separate classes for insertion, deletion, and other functions of the project made sure that we stayed organized as a team, and always knew where we could refer back to if we got disorganized. 
We decided to use a linked list to organize our data so that the driver’s information could be changed, and the program could dynamically adjust to any of those changes. We also made sure to test each function separately before adding it into our project, to make sure that it did what was expected of it before integrating it into the whole system.
14. Updates made Throughout Development
As a group, there were many updates that we made throughout the creation of our database. Originally, we thought that using an excel sheet would be the best way to store the information of our one hundred drivers. After creating our algorithm, we realized that using a text file in visual studio code would be a much easier way to store the information. Other updates we implemented included rewriting functions to be more efficient and easier to understand.
15. Conclusion
This project successfully demonstrates the use of custom data structures to build an efficient driver database system.
It fulfills all requirements and ensures fast performance.
The system showcases strong understanding of data structures and object-oriented design.


