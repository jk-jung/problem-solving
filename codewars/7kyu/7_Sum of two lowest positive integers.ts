export function sumTwoSmallestNumbers(numbers:Array<number>):number {
    numbers.sort((a, b) => a - b);
    return numbers[0] + numbers[1];
}