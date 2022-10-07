hile (temp->next != NULL) {
        if (temp->next->data == x) {
            pushBackNode(temp, temp->next);
        }
        temp = temp->next;
    }  
    printList(head);