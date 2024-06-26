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
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

function dayOfProgrammer(year: number): string {
    // Write your code here
    if (year === 1918) {
        return "26.09." + year;
    }
    let isLeapYear : boolean = false;
    if (year <= 1917 && year % 4 == 0) {
        isLeapYear = true;
    } else if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
        isLeapYear = true;
    }
    if (isLeapYear) {
        return "12.09." + year;
    } else {
        return "13.09." + year;
    }

}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const year: number = parseInt(readLine().trim(), 10);

    const result: string = dayOfProgrammer(year);

    ws.write(result + '\n');

    ws.end();
}
