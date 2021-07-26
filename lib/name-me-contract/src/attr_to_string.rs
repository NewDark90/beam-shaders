//Not used, but at least it's defined and it might be later somehow.
pub fn attr_to_string(attr: u8) {
    if (attr == 0) return "cool";
    if (attr == 1) return "neat";
    if (attr == 2) return "great";
    if (attr == 3) return "indifferent";
    if (attr == 4) return "stronk";
    if (attr == 5) return "smart";
    if (attr == 6) return "kind";
    if (attr == 7) return "friendly";

    return "undefined?";
}