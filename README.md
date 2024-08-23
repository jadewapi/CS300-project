# Project Reflection - Course Data Management

## Problem Statement
The primary challenge of this project was to design a program that could efficiently read, store, and manage course information from a file. The project involved using different data structures such as Vectors, Hash Tables, and Binary Search Trees (BST) to store courses and their prerequisites while maintaining ease of access, performance, and accuracy when querying the data.

## Approach
The first step was to identify the best data structure to solve the problem efficiently. Each data structure had to be evaluated based on its strengths and weaknesses in terms of insertion, deletion, search operations, and memory usage. We explored three main structures—Vectors, Hash Tables, and Binary Search Trees—and implemented pseudocode for each of them to load the courses, handle errors, and print course information in various ways.

Understanding data structures is critical because they directly impact the performance and scalability of a program. Choosing the right data structure depends on the nature of the operations that will be performed, such as how frequently data will be inserted, accessed, or modified.

## Overcoming Roadblocks
One of the key challenges was ensuring that the program could handle different kinds of data formatting issues from the file input. I encountered errors when the course data was incomplete or contained invalid prerequisites. By implementing validation checks within the data-loading functions, I was able to detect and handle these errors gracefully.

Additionally, selecting the right data structure for the project posed some initial difficulties. While Vectors were straightforward to use, their inefficiency with dynamic operations like insertion and deletion made them less than ideal for this problem. Hash Tables provided excellent performance for lookup and insertion, but managing hash collisions was a challenge that I overcame by exploring different collision resolution strategies.

## Expanding Software Design Skills
Working on this project significantly expanded my approach to designing software. It taught me to think critically about how different data structures impact not only performance but also the complexity of the codebase. I learned the importance of balancing the needs of the program—such as speed, memory usage, and maintainability—when choosing between different solutions. This reinforced the idea that software design isn't just about solving the problem at hand but doing so in a way that is scalable and efficient in the long term.

## Writing Maintainable Code
Through this project, I realized the importance of writing code that is maintainable, readable, and adaptable. Using classes and functions to encapsulate the logic for loading, storing, and printing course information helped keep the code organized. Structuring the program in a modular way allows for easy adjustments or additions in the future without needing to refactor the entire codebase.

Using pseudocode helped me outline the logic clearly before implementing the actual code, making the transition to real code smoother and reducing the likelihood of logical errors. I also learned how documenting my approach and thought process made the code easier to understand for others who might work on it in the future—or even for myself when I revisit the project later.

## Conclusion
This project was a valuable learning experience that taught me to consider multiple approaches to a problem and evaluate them based on their efficiency, ease of implementation, and maintainability. The focus on data structures reinforced the importance of choosing the right tools for the job, and the reflective approach helped me solidify my understanding and identify areas for future improvement. Going forward, I will be better equipped to make informed decisions about data structures and will continue to prioritize clean, maintainable code in my software development projects.
