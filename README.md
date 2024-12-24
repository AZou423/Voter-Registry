# Group Project for CS310

Full Names: Andrew Zou, Elliot Zou, Calvin Choi

GitHub IDs: AZou423, cchoi11, ElliotZ2

Simulate a voter registry using various data structures such as a Max Heap, Binary Search Tree, Lists, and Vectors

# Commands
Exit the program by typing "quit" into the terminal
Add voters using cmd "voter <firstName> <lastName> <age>" (Voters with the same name will not be added)
To mark a voter as voted use cmd "voted <firstName> <lastName>" (marking a voter as voted removes them from the registry)
To increase support a voter has for a candidate use cmd "support <firstName> <lastName> <amount>" (The more support a voter has the stronger their impact is)
To decrease the likelihood by <amount>% for a voter to go vote use cmd "reduce-likelihood <firstName> <lastName> <amount>" (The lower the likelihood the stronger their impact is)
To chauffeur a voter (remove them from the registry and mark them as voted) use cmd "chauffeur" (This cmd removes the voter with the greatest impact from the registry)




