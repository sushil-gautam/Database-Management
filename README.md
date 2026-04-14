Driver Database Management System
<br>1. Introduction<br>
With the increasing number of road accidents, the efficient management of driver data has become essential.
This project develops a Driver Database Management System using custom-built data structures without relying on STL.
The system ensures efficient storage, retrieval, and management of driver records while maintaining high performance.
<br>2. Objectives<br>
To design a structured system for storing driver information.
To implement efficient searching using hash tables.
To categorize drivers based on age, experience, and work type.
To retrieve newest and oldest drivers using stack and queue.
To handle large datasets efficiently.
<br>3. Problem Statement<br>
The city council requires a system to manage driver data including personal details, license information, and ticket history.
The system must support fast search operations and structured categorization.
It should also track drivers with recent licenses and elderly drivers with possible medical risks.
<br>4. System Architecture<br>
The system is based on Object-Oriented Programming principles.
It uses composition to integrate Address and Date classes inside the Driver class.
The Database class acts as the controller, integrating multiple data structures.
<br>5. Data Structures Used<br>
Hash Table: Used for fast searching of drivers by License ID with average O(1) complexity.
Linked List: Maintains ordered storage and supports flexible insertion.
Stack: Stores recently added drivers to retrieve newest drivers.
Queue: Stores drivers in order to retrieve oldest drivers.
<br>6. Functional Requirements<br>
Insert driver records into the database.
Search drivers using License ID.
Remove drivers from the system.
Display all driver records.
Retrieve N newest drivers.
Retrieve N oldest drivers.
<br>7. Non-Functional Requirements<br>
High performance and fast search operations.
Scalability to handle large datasets.
Error handling for invalid inputs.
Maintainability using modular design.
<br>8. Implementation Details<br>
The system reads driver data from a text file and parses it using string streams.
Safe conversion functions are used to prevent runtime errors.
Each driver is inserted into all relevant data structures simultaneously.
<br>9. Program Flow<br>
Load driver data from file.
Store data into hash table, linked list, stack, and queue.
Display menu options.
Execute operations based on user input.
Repeat until user exits.
<br>10. Time Complexity Analysis<br>
Insertion: O(1)
Search: O(1) average
Deletion: O(1) average
Display: O(n)
Stack/Queue operations: O(1)
<br>11. Limitations<br>
Removal operation does not update all data structures.
Hash table does not dynamically resize.
Age is not automatically calculated from date of birth.
<br>12. Future Enhancements<br>
Add graphical user interface (GUI).
Implement dynamic resizing of hash table.
Improve synchronization between data structures.
Add sorting and filtering features.
Implement database storage instead of text files.	
<br>13. Approach and Reason for Choosing Design<br>
We began our project by designing and creating an algorithm. Throughout this algorithm, we outlined everything we would need within the project, and began planning the easiest and most organized way to accomplish that. We identified exactly what we needed the code to do, including inserting data, updating values, searching, and displaying results then built our design from there. 
We used classes to separate all of the different operations that our system had to perform. Creating separate classes for insertion, deletion, and other functions of the project made sure that we stayed organized as a team, and always knew where we could refer back to if we got disorganized. 
We decided to use a linked list to organize our data so that the driver’s information could be changed, and the program could dynamically adjust to any of those changes. We also made sure to test each function separately before adding it into our project, to make sure that it did what was expected of it before integrating it into the whole system.
<br>14. Updates made Throughout Development<br>
As a group, there were many updates that we made throughout the creation of our database. Originally, we thought that using an excel sheet would be the best way to store the information of our one hundred drivers. After creating our algorithm, we realized that using a text file in visual studio code would be a much easier way to store the information. Other updates we implemented included rewriting functions to be more efficient and easier to understand.
<br>15. Conclusion<br>
This project successfully demonstrates the use of custom data structures to build an efficient driver database system.
It fulfills all requirements and ensures fast performance.
The system showcases strong understanding of data structures and object-oriented design.
