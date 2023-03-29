# Pixels Assignment C++ basics

In this assignment you will peactise problems based on the concepts of arrays, pointers, relationship of arrays and pointers and vectors.

## Basic of C++

Fun with pointers.

Q1. A teacher awards each student with 3 candies at the start of the day. Each time a student misbehaves she takes away 2 candies from them and awards them with an extra candy when they perform well in their tests. There are 4 students in the class.
Write a program to help the teacher distribute the right number of candies.

**Input**
1. No. of tests taken by the teacher
2. Roll no.s who did bad in each test

```
Enter no. of tests taken => 3 
Enter Roll Numbers of 1st test with bad preformance => 1 
Enter Roll Numbers of 2nd test with bad preformance => 2 4
Enter Roll Numbers of 3rd test with bad preformance => 4 1
```

**Expected Output**

```
Final Candies with each student : 
Roll No. 1 => 1
Roll No. 2 => 3
Roll No. 3 => 3
Roll No. 4 => 1
```

**Other Test Cases**

No. of exams = 5
Roll Numbers with bad performance in 1st test = 1 2
Roll Numbers with bad performance in 2nd test = 1 
Roll Numbers with bad performance in 3rd test = 4 2
Roll Numbers with bad performance in 4th test = 3 
Roll Numbers with bad performance in 5th test = 3 2 

*Hint U can use the recently taught concepts of pointer arithmetics*

---

Q2. A shopkeeper keeps a record of his inventory. Write a program to help him change the stock as and when the orders are placed. Too easy right 😉.Let's make things more interesting. Use the concept of pointers to access this two-dimensional array. 

**Input: Initial Table**
| Unique ID of good |Price | In Stock  |
| -------- | -------- | -------- |
|0001      |250       |70        |
|0002      |500       |20        |
|0003      |1000      |50        |
|0004      |1500      |11        |

Note: Show the initial table in the output window as well as the updated table once changes have been made

**Input: Changing the Table**
Change price of 0001 to 370
Change price of 0004 to 1510
Change price of 0003 to 40

Change Quantity of 0004 to 150

Add a new ID 0005 with price 320 and quantity 40

Now, once table is passes as the input rank each of the Unique IDs according to the total cost of each good.

**Sample Output**
```
Rank order : 0004, 0001, 0005, 0002, 0003
```

* Hint an array is stored in a continuous block of memory 😉


**Question with extra points**

Write a similar function but print only the price of the items(use a pointer to a single element of the array), and arrange the ID's in form of descending order of the total price (Here, the ID of the largest total price should be 0001 and ID of the least total price should be 0005)

---

Q3. Lets us build upon our knowledge of pointers and arrays even further. Create a Print function that prints out the entire two-dimensional array. (Pass a pointer array to the  function)

**Sample Input**
```
Enter Number of rows and columns : 3 4

Input enter elements in 1st row : 1, 2, 3, 4
Input enter elements in 2nd row : 5, 6, 7, 8
Input enter elements in 3rd row : 9, 10, 11, 12

```
**Sample Output**

```
 1 2 3 4
 5 6 7 8 
 9 10 11 12
```

---

Q4. We have learned the concepts of vectors now lets use them to render vectors which represent images


Write a logic to display this pattern

* Hint it involves use of multiple concepts like if-else statements and for loops

```
    1 0 0 0 0 1 1 1 1 1  
    1 1 0 0 0 1 1 1 1 0 
    1 1 1 0 0 1 1 1 0 0 
    1 1 1 1 0 1 1 0 0 0
    1 1 1 1 1 1 0 0 0 0
```

Now copy the vector into a new vector and render an inverted vector wherein black is on top and white is at the bottom. 


**ALL THE BEST** 👍

*PS - If you have any doubts don't hesitate to contact us* 😄