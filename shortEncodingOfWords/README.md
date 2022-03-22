Approach

    1.Sort the words in the vector according to their length 

    2.Then insert each word in the reverse way into the trie and if the inserted word is a new word then we add the size of the word to our answer


Dry Run 

    1.words = ["time", "me", "bell"] , ans = 0

    2.After sorting words = ["time", "bell", "me"]

    3.Insert "time" in the trie in reverse way("emit) and since it is a new word add its size+1 to answer (1 because of "#") hence ans = 4+1 => 5

    4.Insert "bell" in the trie in reverse way("lleb) and since it is a new word add its size+1 to answer hence ans = 5+4+1 => 9

    5.Since "em" already exists from "emit" its not a new word hence we dont do anything