# Algorithm_training
_Algorithm exercices followin "Algorithms Illuminated, Part 1: The Basic, by Tim Roughgarden"_
------------------------------------------------------
## 1- Integer multiplication
#### Integer Multiplication problem
----------------------------------------------
> Input: Two n-digit nonnegative integers, x and y
> 
> Output: the product x*y 
-------------------------------------------------
#### 1. Grade-School 
_ see grade school algoithm _
#### 2. Recursive Integer Multipication
-------------------------------------------
>**Input:** two n-digit positive intergs x an y
>
>**Output:** the product x.y
>
>**Assumption:** n is a power of 2
-------------------------------------------
> **if**  _n_ = 1 **then**              // base case
> 
>>  computer _x.y_ in one step and return the result
>   
>  **else**                             // recursive case
>>  
>>   _a,b_:=first and second halves of x
>>  
>>  _c,d_:=first and second halves of y
>>  
>>  recusrively compute _ac_:=_a.c_, _ad_:=_a.d_, _bc_:=_b.c_, and _bd_:=_b.d_
>>  
>>  compute 10<sup>_n_</sup>._ac_+10<sup>_n/2_</sup>.(_ad_+ _bc_)+ _bd_ using grade-school addition and return the result
>>  
#### 4. MultiplicationMergeSort
