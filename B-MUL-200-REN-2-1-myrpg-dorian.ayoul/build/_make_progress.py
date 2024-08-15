# -*- coding: utf-8 -*-

import argparse
import math
import sys


def get_progress_bar(numchars, fraction=None, percent=None):
    if percent is not None:
        fraction = percent / 100.0

    if fraction >= 1.0:
        return "█" * numchars

    blocks = [" ", "▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"]
    length_in_chars = fraction * numchars
    n_full = int(length_in_chars)
    i_partial = int(8 * (length_in_chars - n_full))
    n_empty = max(numchars - n_full - 1, 0)
    return ("█" * n_full) + blocks[i_partial] + (" " * n_empty)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--stepno", type=int, required=True)
    parser.add_argument("--nsteps", type=int, required=True)
    parser.add_argument("--end", dest="end", action="store_true")
    parser.add_argument("remainder", nargs=argparse.REMAINDER)
    args = parser.parse_args()

    nchars = int(math.log(args.nsteps, 10)) + 1
    fmt_str = "T[{:Xd}/{:Xd}] ({:6.2f}%) ".\
        replace("T", "\r" if not args.end else "").\
        replace("X", str(nchars))
    progress = 100 * args.stepno / args.nsteps
    if args.end and args.stepno == 0:
        print("{0} No file updated.".format(args.remainder[0]))
        return
    if args.stepno != args.nsteps and args.end:
        print("")
    sys.stdout.write(fmt_str.format(args.stepno, args.nsteps, progress))
    color = "\033[1;33m"
    if args.end:
        color = "\033[1;32m"
    sys.stdout.write("{0}{1}\033[0m".format(color, get_progress_bar(20, percent=progress)))
    remainder_str = " ".join(args.remainder)
    sys.stdout.write(" {0}                      ".format(remainder_str).replace(".o", ".c"))
    if args.stepno == args.nsteps or args.end:
        print("")


if __name__ == "__main__":
    main()