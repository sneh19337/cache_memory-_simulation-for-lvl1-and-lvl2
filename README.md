# cache_memory-_simulation-for-lvl1-and-lvl2
The cpproject shows the simulation of how a cache memory works and different mapping techniques 
1.The program assumes that the cache memory is a 16 bits architecture and       the main memory is 32 bits architecture.     
2.The program assumes that the n-way set associative memory mapping is provided with a value where n is power of 2.
3.The program assumes that the cache lines is also an input which is a power of 2.
4.The program assumes that the block numbers is also an input which is a power of 2.
5.The program assumes that the inputs given are in the range of the data otherwise the inputs are ignored.
6.This program assumes that the block number and the data are input in the form of decimal numbers. 

7.The program assumes the cache lines indexing and block number indexing  starts from 0.
8.The program assumes that initially all the cache and main memory has all the data as 0 . It will fill with values once the data is entered.
9.In case a new data comes to be written in the cache and it finds that the block is already filled where it was to be written . MRU(Most Recently Used) caching will take place and the data will be written in the block and the data previously stored will be overwritten.
10. The program will find the hit/miss and the block number whose data is missed for all the three types of data at once and will show them each time the searching happens.
11. The bonus assignment is also done in this project code .The user needs to choose the second option to enter in bonus assignment .
12. Level-2 cache has size twice  that of level-1 cache. i.e., level-2 is 32 bits architecture and level-1 is 16 bits architecture.

DETAILED EXPLANATION OF CODE
The program starts with asking the user for certain required information for making a cache memory. It asks for cache lines, block numbers, the data in the block, the number of times the system should find the data in the memory.
Now once entered these details the program will start and the blocks which the user has entered to see the cache memory allocation will take place one by one. The program will show the cache structure at each step of the searching process which is taking place in the program. Once a data is not found in the required block a “Cache Miss” will be shown and the program will show the  block number where the data is missed . Now the program shows the cache lines where we can see that block in the cache line . If a data is found “Cache Hit” occurs and the program simply shows 1 as the value of hit to show that the data is found. This process continues till all the search operations are done. If a data is already found in a block where a new data is to be written. The older data will be removed and the new data will be overwritten in the block. It’s because the address is previously visited so the next data if is to be written on the same block then the system will make another visit to the address. So, we need to remove the previous data from there. This way the program will continue running and stops when all the searches are done.  
This program has choices (1,2,3) the first one takes user to the program which shows the mapping technique comparison in cache memory. The second option takes the user to the bonus assignment where the level -2 cache memory mapping is shown which is not dependent on main memory. The last option tells the user that the user is out of program options possible . 
For Example-
THIS DOES NOT SHOWS THE COMPLETE PROGRAM BUT JUST A SNIPPET OF HOW THE PROGRAM WORKS 

Enter your choice (1,2)
1
******************************************************************************************************************************************************************************************************************************************************************
This is a demo program for showing and comparing the different mapping techniques of cache memory

Enter Cache Lines :
16
******************************************************************************************************************************************************************************************************************************************************************

Input the no of data to be read  from Cache:
2
******************************************************************************************************************************************************************************************************************************************************************

The data you want from main memory:
2
******************************************************************************************************************************************************************************************************************************************************************

The data you want to check from cache :
2
******************************************************************************************************************************************************************************************************************************************************************

Enter the no. of Sets(out of -2,4,8,16,32,64) in Set Associative Mapping:
4
***********************************************************************************************************
*********************************************************************************************************************************

  Blocks


Enter  Block No.


Enter the blocks which you want to see in cache
4
5
4
8
7
9
6
3
1
***********************************************************************************************************
*********************************************************************************************************************************



                        A Mock Representation Of Data in the block

Block     Data
   3         1
   5         4
   8         7
   9         6
*********************************************************************************************************************************************************************************************************************************************

How many checks  you want to be made by the system: 2


Data Replacement (MRU ) will take place if you try to add data to the same block. Hence what you will see will be the lastly entered data in the block

 Specify Block numbers to get the cache structure at every step of WRITE/READ in cache
4
6
******************************************************************************************************************************************************************************************************************************************************************



From the data      4  mapped to         0
 Direct Mapping : 2
                        Hit       =1

Associative Mapping : 4
                        Hit       =1

 n- Set Associative Mapping : 2
                        Hit        =1

Enter your choice (1,2)
2
The program here will be implementing the bonus assignment of implementing level 2 cache memory without the intervention of main memory
******************************************************************************************************************************************************************************************************************************************************************
This is a demo program for showing and comparing the different mapping techniques of cache memory in level2 cache without main memory

Enter Cache Lines in level 2 cache memory :
4
******************************************************************************************************************************************************************************************************************************************************************

Input the no of data to be read  from lvl2 Cache:
1
1
1
******************************************************************************************************************************************************************************************************************************************************************

Enter the no. of Sets(out of -2,4,8,16,32,64) in Set Associative Mapping:
2
***********************************************************************************************************
*********************************************************************************************************************************








                        Blocks


Enter  Block No.


Enter the blocks which you want to see in cache
2
1
3
1
5
***********************************************************************************************************
*********************************************************************************************************************************



                        A Mock Representation Of Data in the block in level 1 cache memory

Block     Data
   1         5
*********************************************************************************************************************************************************************************************************************************************

How many checks  you want to be made by the system: 2


Data Replacement (MRU ) will take place if you try to add data to the same block.Hence what you will see will be the lastly entered data in the block

 Specify Block numbers to get the cache structure at every step of WRITE/READ in cache
1
4
******************************************************************************************************************************************************************************************************************************************************************



From the data      1  mapped to         5
 Direct Mapping : 2
Miss occurred at= 5
                        Hit       =0

 Associative Mapping :6
Miss occurred at = 5
                        Hit       =0

 n-Set Associative Mapping  : 6
Miss occurred at =5
                        Hit        =0

ERROR -REPORTING
1.Once the data goes beyond the memory the program will show an error.
2.The program will show an error if the data entered by user for cache lines, block numbers, set associativity is not in power of 2 then the program will show error.
3. If the data which the user wants to write at a block has already written data the data will get overwritten with the new data which can be seen in the cache structure showing the new data at the cache lines. This overwriting process is done through the MRU (Most Recently Used) caching technique.
4.If the value of n  in  n set associative mapping becomes more than 128 or the block number entered is more than 255 the program will show an error. 
5. If the user chooses any other choice other than 1,2,3 then the program will show an error.  
  

