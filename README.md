# game-chain
chain reaction game wirtten in cpp


## to play the game
* make sure c++ compiler is installed.
* For linux, in the game-chain directory run \
``` g++ genchain.cpp && ./a.out```
* For windows, simply compile and run the "genchain.cpp" file in your favourite\
c++ ide.
* there you go, for entering coordinates, supply two numbers seperated by space.

### example
<pre>
        1   2   3   4   5   
        |   |   |   |   |   
        v   v   v   v   v   
        
  1-&gt;   `0  `0  `0  `0  `0  
  2-&gt;   `0  `0  `0  `0  `0  
  3-&gt;   `0  `0  `0  `0  `0  
  4-&gt;   `0  `0  `0  `0  `0  
  5-&gt;   `0  `0  `0  `0  `0  


	Now turn for player :- 1
next coordinates : 1 1
updated here


        1   2   3   4   5   
        |   |   |   |   |   
        v   v   v   v   v   
        
  1-&gt;   a1  `0  `0  `0  `0  
  2-&gt;   `0  `0  `0  `0  `0  
  3-&gt;   `0  `0  `0  `0  `0  
  4-&gt;   `0  `0  `0  `0  `0  
  5-&gt;   `0  `0  `0  `0  `0  


	Now turn for player :- 2
next coordinates : 2 3
updated here



        1   2   3   4   5   
        |   |   |   |   |   
        v   v   v   v   v   
        
  1-&gt;   a1  `0  `0  `0  `0  
  2-&gt;   `0  `0  b1  `0  `0  
  3-&gt;   `0  `0  `0  `0  `0  
  4-&gt;   `0  `0  `0  `0  `0  
  5-&gt;   `0  `0  `0  `0  `0  


	Now turn for player :- 1
next coordinates : 


</pre>
