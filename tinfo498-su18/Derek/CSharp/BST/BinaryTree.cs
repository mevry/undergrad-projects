using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace BST
{
    public class BinaryTree<TId,T> where TId : IComparable<TId>
    {
        Node<TId,T> _root;
        int _count = 0;
        public int Count { get { return _count; } }

        public BinaryTree() { }
        public BinaryTree(TId id, T data)
        {
            _root = new Node<TId,T>(id, data);
        }
        
        public void Insert(T data)
        {
            throw new Exception("Not implemented");
        }

 
    }
}
