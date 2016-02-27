package;

import luxe.Input;
import luxe.Vector;
import luxe.Visual;
import luxe.Text;
import luxe.Color;
import luxe.tween.Actuate;

class Box extends Visual {
    static var SIZE = 150;
    public var x :Int;
    public var y :Int;
    var text :Text;

    public function new(x :Int, y :Int) {
        this.x = x;
        this.y = y;
        super({
            pos: Vector.Add(Vector.SubtractScalar(Luxe.screen.mid, SIZE * 1.5), new Vector(x * SIZE, y * SIZE)),
            size: new Vector(SIZE, SIZE),
            color: new Color(0.6, 0.6, 0.6, 0.5),
            scale: new Vector(0, 0)
        });

        new Visual({
            pos: new Vector(SIZE * 0.05, SIZE * 0.05),
            size: new Vector(SIZE * 0.9, SIZE * 0.9),
            color: new Color(0.75, 0.75, 0.75, 0.5),
            parent: this
        });

        text = new Text({
            text: '',
            pos: new Vector(SIZE * 0.5, SIZE * 0.5),
            point_size: 72,
            align: luxe.Text.TextAlign.center,
            align_vertical: luxe.Text.TextAlign.center,
            color: new luxe.Color(0.2, 0.2, 0.2),
            parent: this
        });

        Actuate
            .tween(this.scale, 0.5, { x: 1, y: 1 })
            .delay(x * 0.2 + y * 0.5)
            .ease(luxe.tween.easing.Cubic.easeInOut);
    }

    override public function onmousedown(e :MouseEvent) {
        if (Luxe.utils.geometry.point_in_geometry(e.pos, geometry)) {
            events.fire('click');
        }
    }

    public function assign(symbol :String) {
        text.text = symbol;
        Actuate
            .tween(text, 0.3, { rotation_z: 90 })
            .reflect()
            .repeat(1)
            .ease(luxe.tween.easing.Cubic.easeInOut);
    }

    public function get_symbol() :String {
        return text.text;
    }

    public function has_symbol() :Bool {
        return text.text.length > 0;
    }
}
