class Playground {
  constructor(ctx) {
    this.ctx = ctx;
  }

  clear(x, y, level) {
    this.ctx.fillStyle = "green";
    this.ctx.arc(x, y, level, 0, 2 * Math.PI);
    this.ctx.fill();
  }

  pee(x, y, level) {
    this.ctx.fillStyle = "yellow";
    this.ctx.beginPath();
    this.ctx.arc(x, y, level, 0, 2 * Math.PI);
    this.ctx.strokeStyle = "yellow";
    this.ctx.stroke();
  }

  doAction(x, y, level) {}
}

module.exports = Playground;
