using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    class PeakFinder
    {
        public static Tuple<bool, int> findPeak(List<int> arr)
        {
            int n = arr.Count / 2;

            if (n - 1 > 0 && arr[n] < arr[n - 1])
            {
                return findPeak(new List<int>(arr.GetRange(0, n)));
            }
            else if (n + 1 < arr.Count && arr[n] < arr[n + 1])
            {
                return findPeak(new List<int>(arr.GetRange(n, arr.Count)));
            }
            else
                return new Tuple<bool, int>(true, arr[n]);
        }

        private static int findGlobalMax(int[,] arr2D, int col)
        {
            int ret = 0;

            for (int row = 0; row < arr2D.GetLength(0); ++row)
            {
                if (arr2D[row, col] > arr2D[ret, col])
                {
                    ret = row;
                }
            }

            return ret;
        }

        public static Tuple<bool, int> findPeak_2D(int[,] arr2D, int start_row, int end_row, int start_col, int end_col)
        {
            int col = start_col + (end_col - start_col) / 2;
            int row = findGlobalMax(arr2D, col);

            if (start_col <= col - 1 && arr2D[row, col] < arr2D[row, col - 1])
            {
                return findPeak_2D(arr2D, start_row, end_row, start_col, col);
            }
            else if (end_col > col + 1 && arr2D[row, col] < arr2D[row, col + 1])
            {
                return findPeak_2D(arr2D, start_row, end_row, col, end_col);
            }
            else
            {
                return new Tuple<bool, int>(true, arr2D[row, col]);
            }
        }
    }
}
