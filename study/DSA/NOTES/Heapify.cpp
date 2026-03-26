// To heapify a subtree rooted 
function heapify(arr, n, i) {
    let largest = i;
    let l = 2 * i + 1; 
    let r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest !== i) {
        [arr[i], arr[largest]] = [arr[largest], arr[i]];

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from the given array
function buildHeap(arr) {
    const n = arr.length;
    
    // Index of last non-leaf node
    let startIdx = Math.floor(n / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (let i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Driver Code
// Binary Tree Representation of input array
//             1
//           /    \
//         3        5
//       /  \     /  \
//     4      6  13  10
//    / \    / \
//   9   8  15 17
const arr = [1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17];
const n = arr.length;

// Build Max Heap
buildHeap(arr);

for (let i = 0; i < n; i++)
    process.stdout.write(arr[i] + " ");
console.log("\n");

// Final Heap Representation
//              17
//            /    \
//          15      13
//         /  \     / \
//        9     6  5   10
//       / \   / \
//      4   8 3   1