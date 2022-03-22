Approach

    1.Create a trie which has links of size 26 and a value which holds the sum of all prefixes that were inserted in the map

    2.While inserting the key value pair in the trie check if the map already has the key if yes then update the value to be inserted and then 
    insert the key value pair into the map

    3.For sum function we can just return the value stored at the ending letter of the prefix

    4.The code gives better understanding