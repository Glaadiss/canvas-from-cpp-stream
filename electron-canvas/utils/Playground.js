const img = new Image();
img.src = "./images/k.png";

class Playground {
  constructor(ctx) {
    this.ctx = ctx;
  }

  CLEAR(x, y, level) {
    this.doAction(x, y, level, "green");
  }

  PEE(x, y, level) {
    this.doAction(x, y, level, "yellow");
  }

  RABBIT(x, y, level) {
    this.doXD(x, y, level * 2);
  }

  doXD(x, y, level) {
    this.ctx.drawImage(img, x - level / 2, y - level / 2, level, level);
  }

  doAction(x, y, level, color) {
    this.ctx.fillStyle = color;
    this.ctx.beginPath();
    this.ctx.arc(x, y, level, 0, 2 * Math.PI);
    this.ctx.strokeStyle = color;
    this.ctx.stroke();
  }
}

module.exports = Playground;
