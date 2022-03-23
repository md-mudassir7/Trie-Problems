Approach

    1.Create a trie and insert all the words in the trie as the function addWord gets called each time

    2.Then for search we use dfs i.e we check if the character exists in the trie and move to the node containing that character

    3.If the current character is a '.' then we perform checks for all the characters that can be inserted instead of '.' and if that will 
    form the word in the trie

    4.Go through lines 43-49 in the code for better understanding