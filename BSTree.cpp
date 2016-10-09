
#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr )
{
	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;



}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ()
{
	root = NULL;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ( const BSTree<DataType,KeyType>& other )
{

	BSTreeCopyHelper(source.root, root);

}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::BSTreeCopyHelper(BSTreeNode *p1, BSTreeNode *&p2)
{
	if (p1 == NULL)
		p2 == NULL;

	else
	{
		ExprTreeNode *newNode = new ExprTreeNode(p1->dataItem, NULL, NULL);

		p2 = newNode;

		p2->dataItem = p1->dataItem;
		copyHelper(p1->left, p2->left);
		copyHelper(p1->right, p2->right);


	}
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= ( const BSTree<DataType,KeyType>& other )
{
	this.clear();

	this = source;


}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree ()
{

	clear();

}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem )
{
	
	insertHelper(newDataItem, root);



}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insertHelper(const DataType& newDataItem, BSTreeNode *&p)
{

	if (p == NULL)
		p = new BSTreeNode(newDataItem, NULL, NULL);

	else if (p->dataItem.getKey() > newDataItem.getKey())
		insertHelper(newDataItem, p->left);
	else if (p->dataItem.getKey() < newDataItem.getKey())
		insertHelper(newDataItem, p->right);
	



}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem )
{

	return retrieveHelper(searchKey, searchDataItem, root);

	
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieveHelper(const KeyType& searchKey, DataType& searchDataItem, BSTreeNode *&p) 
{

	if (p != NULL)
	{
		if (p->dataItem.getKey() == searchKey)
		{
			searchDataItem = p->dataItem;
			return true;

		}

		retrieveHelper(searchKey, searchDataItem, p->left);
		retrieveHelper(searchKey, searchDataItem, p->right);


	}

	if (searchDataItem.getKey() != searchKey)
		return false;

	
	
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey )
{

	return removeHelper(deleteKey, root);

	
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::removeHelper(const KeyType& deleteKey, BSTreeNode *&p)
{

	if (p == NULL)
		return false;

	if (p != NULL)
	{

		if (deleteKey < p->dataItem.getKey())
			removeHelper(deleteKey, p->left);

		else if (deleteKey > p->dataItem.getKey())
			removeHelper(deleteKey, p->right);

		else
		{
			BSTreeNode *deleteNode = p;

			if (p->left == NULL)
			{
				p = p->right;                   
				delete deleteNode;
			}
			else if (p->right == NULL)
			{
				p = p->left;                     
				delete deleteNode;
			}

			else if ((p->left != NULL) && (p->right != NULL))
			{
				BSTreeNode *tempNode = p->right;
				
				while (tempNode -> left != NULL )
					tempNode = tempNode->left;
				
				p->dataItem = tempNode->dataItem;
				
				
				removeHelper(tempNode->dataItem.getKey(), p->right);



			}



			return true;








		}








	}

	

	
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys () const
{

	writeKeysHelper(root);


}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode *p) const
{

	if (p != NULL)
	{

		writeKeysHelper(p->left);
		cout << p->dataItem.getKey() << "  ";
		writeKeysHelper(p->right);


	}



}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear ()
{

	clearHelper(root);

	root = NULL;

}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clearHelper(BSTreeNode *p)
{

	

	if (p != NULL)
	{
	
		clearHelper(p->left);
		clearHelper(p->right);
		delete p;

	}

	p = NULL;

}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::isEmpty () const
{
	if (root == NULL)
		return true;

	else
	return false;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight () const
{
	int height = 0;

	height = getHeightHelper(root, height);

	return height;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeightHelper(BSTreeNode *p, int height) const
{
	int left;
	int right;
	
	if (p == NULL)
		return 0;

	if (p != NULL)
	{
		int left = getHeightHelper(p->left, height);
		int right = getHeightHelper(p->right, height);

		if (left >= right)
			return left + 1;
		else
			return right + 1;

	}

	return height;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount () const
{
	int count = 0;

	count = getCountHelper(root, count);

	return count;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCountHelper(BSTreeNode *p, int &count) const
{
	
	

	if (p != NULL)
	{
		count++;
		getCountHelper(p->left, count);
		getCountHelper(p->right, count);


	}

	return count;
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeLessThan ( const KeyType& searchKey ) const
{

	writeLessThanHelper(searchKey, root);

}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeLessThanHelper(const KeyType& searchKey, BSTreeNode *p) const
{

	

	if (p != NULL)
	{

		

		
		writeLessThanHelper(searchKey, p->left);

		if (p->dataItem.getKey() < searchKey)
		{
			
			cout << p->dataItem.getKey() << " ";
		}

		writeLessThanHelper(searchKey, p->right);

		


	}



}


#include "show9.cpp"