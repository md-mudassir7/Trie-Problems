Approach

    1.We insert all the elements of products array in the trie

    2.Then we traverse the searchWord string character by character and store in a variable called prefix

    3.Then we find atmost 3 words in our trie which are starting with this prefix

Dry run

    1.products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"

    2.prefix = "m" we traverse the trie until the end of prefix and then explore the different characters words 

    3.prefix = "mo" we traverse until "o" and then find atmost 3 words staring with "mo"

    4.Similarly for all other prefixes "mou","mous","mouse"

    5.The code gives a proper understanding