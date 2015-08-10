using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    class InsertionSort
    {
        public static void InsertSort(ref List<int> arr)
        {
            for (int i = 0; i < arr.Count; ++i)
            {
                int current = arr[i];

                for(int pos = i; pos > 0 && arr[pos] < arr[pos - 1]; --pos)
                {
                    arr[pos] = arr[pos - 1];
                    arr[pos - 1] = current;
                }
            }
        }
    }
}
