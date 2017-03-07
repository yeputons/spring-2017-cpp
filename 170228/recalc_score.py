#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
import sys
import pyperclip


def main():
    a, b, c, d = map(int, sys.argv[1:])
    s1 = a + b + c + d
    assert 0 <= a <= 3
    assert 0 <= b <= 2
    assert 0 <= c <= 2
    assert 0 <= d <= 3
    x = int(b >= 1)
    y = int(b >= 2)

    txt = []
    txt.append("Баллы пересчитаны (см. [http://mit.spbau.ru/sewiki/index.php/%D0%A1%2B%2B,_1_%D0%BA%D1%83%D1%80%D1%81,_3_%D0%B3%D1%80%D1%83%D0%BF%D0%BF%D0%B0,_2_%D1%81%D0%B5%D0%BC%D0%B5%D1%81%D1%82%D1%80,_2016/17#.D0.9B.D0.B0.D0.B1.D0.BE.D1.80.D0.B0.D1.82.D0.BE.D1.80.D0.BD.D0.B0.D1.8F_12_.28.D0.B2.D0.B5.D0.BA.D1.82.D0.BE.D1.80.D0.B0.29 SEWiki] для формулы).")
    txt.append("Было {}+{}+{}+{}={} (x={}, y={}).".format(a, b, c, d, s1, x, y))

    def round1(v):
        return round(v, 1)
    vs = [a * 4 / 3, 4 * x, y, c, d]
    assert len(vs) == 5
    s2 = round(vs[0] + vs[1] + 2 / 6 * sum(vs[2:]) + 0.001)
    txt.append("Стало {} + {} + 2/6*({} + {} + {}) ~ {}.".format(*map(round1, vs), s2))

    if s1 > s2:
        txt.append("В табличке оставлены старые баллы, чтобы не уменьшать.")

    txt = "\n\n".join(txt) + "\n"
    pyperclip.copy(txt)
    print(txt)


if __name__ == "__main__":
    main()
