'use strict';

import { WriteStream, createWriteStream } from "fs";
process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';

    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

/*
 * Complete the 'beautifulTriplets' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

function beautifulTriplets(d: number, arr: number[]): number {
    // Write your code here
    let count : number = 0;
    
    // count the number of pairs (value, count)
    const countMap = new Map();
    for (const value of arr) {
        if (! countMap.has(value)) {
            countMap.set(value, 1);
        } else {
            countMap.set(value, countMap.get(value) + 1);
        }
    }
    
    // create a list distinc value from arr
    const distinctValue  = new Set(arr)
    const distinctArr = Array.from(distinctValue)
    
    // start loops
    let i = 0
    while ( i < distinctValue.size - 2) {
        let j = i + 1
        while (j < distinctValue.size - 1 && distinctArr[j] - distinctArr[i] <= d) {
            if (distinctArr[j ] - distinctArr[i] == d) {
                let k = j + 1
                while (k < distinctValue.size && distinctArr[k] - distinctArr[j] <= d) {
                    if (distinctArr[k] - distinctArr[j] == d) {
                        count += countMap.get(distinctArr[i]) * countMap.get(distinctArr[j]) * countMap.get(distinctArr[k]);
                        break;
                    } else {
                        k++;
                    }
                }
                break;
            } else {
                j++;
            }
        }
        i++;
    }
    return count
}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const firstMultipleInput: string[] = readLine().replace(/\s+$/g, '').split(' ');

    const n: number = parseInt(firstMultipleInput[0], 10);

    const d: number = parseInt(firstMultipleInput[1], 10);

    const arr: number[] = readLine().replace(/\s+$/g, '').split(' ').map(arrTemp => parseInt(arrTemp, 10));

    const result: number = beautifulTriplets(d, arr);

    ws.write(result + '\n');

    ws.end();
}
