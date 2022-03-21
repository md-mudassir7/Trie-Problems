Approach 1 (sorting)

    1.Sort the strings in the folder

    2.Insert the first word in answer and loop until the next string is not a subfolder of the first

    3.Similarly traverse till the end


Approach 2 (Trie)

    1.Sort the strings in the folder

    2.We insert the strings into the trie only if their parent folder does not exist in the trie

    3.The code gives better understanding of the above statement (lines 52-66)