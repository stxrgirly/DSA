void CreateList(int n) {
    int i;
        node * newnode;
        node * temp;
            for (i = 0, i < n; i++) {
                newnode = getnode();
                if(start == NULL) {
                    start = newnode;
                }
                else {
                    temp = start;
                        while(temp->next != NULL) {
                            temp = temp->next;
                            temp->next = newnode;
                        }
                }
            }
}
