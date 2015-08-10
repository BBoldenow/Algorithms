using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PeakFinder
{ 
    class Program
    {
        private static Tuple<bool, int> findPeak(int[] arr, int start, int end)
        {
            int n = start + (end - start) / 2;

            if (n - 1 > 0 && arr[n] < arr[n - 1])
            {
                return findPeak(arr, start, n);
            }
            else if (n + 1 < end && arr[n] < arr[n + 1])
            {
                return findPeak(arr, n, end);
            }
            else
                return new Tuple<bool, int>(true, arr[n]);
        }

        private static int findGlobalMax(int[,] arr2D, int col)
        {
            int ret = 0;

            for(int row = 0; row < arr2D.GetLength(0); ++row)
            {
                if(arr2D[row, col] > arr2D[ret, col])
                {
                    ret = row;
                }
            }

            return ret;
        }

        private static Tuple<bool, int> findPeak_2D(int[,] arr2D, int start_row, int end_row, int start_col, int end_col)
        {
            int col = start_col + (end_col - start_col) / 2;
            int row = findGlobalMax(arr2D, col);

            if(start_col <= col - 1 && arr2D[row, col] < arr2D[row, col - 1])
            {
                return findPeak_2D(arr2D, start_row, end_row, start_col, col);
            }
            else if(end_col > col + 1 && arr2D[row, col] < arr2D[row, col + 1])
            {
                return findPeak_2D(arr2D, start_row, end_row, col, end_col);
            }
            else
            {
                return new Tuple<bool, int>(true, arr2D[row, col]);
            }
        }

        static void Main(string[] args)
        {
            //int[] arr = { 1, 9, 5, 4, 3, 6, 7 };
            //Tuple<bool, int> result = findPeak(arr, 0, arr.Length);

            int[,] arr2D =
            {
                { 10, 10, 8, 10 },
                { 11, 12, 13, 14 },
                { 21, 11, 9, 15 },
                { 20, 19, 17, 16 }
            };

            var result = findPeak_2D(arr2D, 0, arr2D.GetLength(0), 0, arr2D.GetLength(1));

            System.Diagnostics.Debug.WriteLine("Found peak: {0}, and the peak value is: {1}", result.Item1, result.Item2);
        }
    }
}
