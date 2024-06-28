const input = require("fs").readFileSync(process.platform === "linux" ? "/dev/stdin" : __dirname + "/input.txt").toString().trim().split("\n").map(BigInt);
input.slice(0, -1).forEach((ticket) => {
    if (ticket % BigInt(42) === BigInt(0)) console.log("PREMIADO");
    else console.log("TENTE NOVAMENTE");
});