const input =  require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().split(" ");
const A = BigInt(input[0]);
const B = BigInt(input[1]);
console.log((A * B).toString());