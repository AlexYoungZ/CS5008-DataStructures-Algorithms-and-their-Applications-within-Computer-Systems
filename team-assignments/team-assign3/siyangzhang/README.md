stack and queue can be made by both vector and linked list;

Stack | Push | Pop | Peek | Memory overhead |    
--------------- | --------------- | --------------- | --------------- | --------------- |     
LinkedList Stack | O(1) | O(1) | O(1) | O(n) for extra pointer |     
Vector Stack | O(n), amortized O(1) | O(1), amortized O(1) | O(1) | O(1) normally, O(n) unused after dynamically allocated |    

If allocation is infrequent, vector based is faster than linked list.    
It depends on which type of operations are more frequent and user demands.    

Queue | Enqueue | Dequeue | Memory overhead |    
--------------- | --------------- | --------------- | --------------- |    
LinkedList Queue | O(1) | O(1) | O(n) for extra pointer |    
Vector Queue | O(1) | O(n) | O(1) |    

circular buffer helps.    

- Did you use any external resources? (Cite them below)    
    - https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/