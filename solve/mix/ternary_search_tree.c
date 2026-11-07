#include <stdio.h>
#include <stdlib.h>

typedef struct ternary_node {

	struct ternary_node * left;
	struct ternary_node * middle;
	struct ternary_node * right;
	int key;

} ternary_node_t;

ternary_node_t * create_new_node(int key) {
	ternary_node_t * new_node = (ternary_node_t *) malloc(sizeof(ternary_node_t));
	new_node->key = key;
	new_node->left = new_node->middle = new_node->right = NULL;
	return new_node;
}

ternary_node_t * insert(ternary_node_t * root, int key) {

	ternary_node_t * new = create_new_node(key);

	ternary_node_t * curr = root;

	while (curr != NULL) {
		if (curr->key > key) {
			if (curr->right == NULL) {
				curr->right = new;
				return curr;
			}
			curr = curr->right;
		} else if (curr->key == key) {
			if (curr->middle == NULL) {
				curr->middle = new;
				return curr;
			}
			curr = curr->middle;
		} else {
			if (curr->left == NULL) {
				curr->left = new;
				return curr;
			}
			curr = curr->left;
		}
	}

	curr = new;
	return NULL;
}

int main(void) {

	int n;
	scanf("%d", &n);

	int root_key;
	scanf("%d", &root_key);

	ternary_node_t * root = create_new_node(root_key);

	int parent_keys[n - 1];

	for (int i = 0; i < n - 1; ++i) {
		int new_key;
		scanf("%d", &new_key);

		ternary_node_t * temp = insert(root, new_key);

		parent_keys[i] = temp->key;
	}

	for (int i = 0; i < n - 1; ++i)
		printf("%d\n", parent_keys[i]);

	return 0;
}