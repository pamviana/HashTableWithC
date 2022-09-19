Description:
The program first declares and initializes the hashtable by calling initializeTable(). 
Then, it reads the .txt file that contains the student data. 
Each line is tested, calling testRecord, to make sure the record is not empty, has the proper length and contains exactly 4 commas. 
If the record is good, the method createStudent is called; it creates a record of type struct student. 
If it is not, an error would be displayed. The data returned by createStudent is tested, and if it is good, it is inserted into the hashtable. 
This process is simple: first a hashing number will be computed based on the student’s name, and an attempt will be made to insert it to that hashtable’s index. If a student already exists in that position, it will try to insert it into the next null position. After inserting all the students to the hashtable, all the records will be displayed, containing all the students’ information.


Extra Credit:
I attempted the extra credit.

Shortcomings:
No shortcomings exist.

Experience:
I got very excited when I found out what project 1 entailed. I have been working as Software Engineer intern at Beeline, and my job is very similar to this project’s outline. I’m responsible for testing out data that was imported from customers, insert it in our database, and display errors in case it is bad data. It appears to be an easy task, but it can get very complicated, because of all the business logic behind it, and the fact the work needs to be done in a legacy system. The latter brings up an important point about this project, the fact the functions and the files were already outlined for us. It seems the students were not a big fan of how they had to follow the pattern you set up, but in my opinion, it is great practice for the real world. We don’t always get an opportunity to write an application from scratch, but you do need to follow the company's patterns and outlines; and in a lot of cases, there are no instructions for that.

The most difficult part for me was dealing with C. I have never written a program in C, and the idea of pointers made me spend more time on this project than I expected. But after watching some videos, and understanding all of the concepts, everything started to make more sense and the project went smoothly.

Improvements:
No improvements.
