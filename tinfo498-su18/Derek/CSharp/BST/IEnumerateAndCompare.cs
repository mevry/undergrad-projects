using System;
using System.Collections.Generic;
using System.Text;

namespace BST
{
    public interface IEnumerableAndComparable<T> : IEnumerable<T>, IComparable<T>
    {
    }
}
