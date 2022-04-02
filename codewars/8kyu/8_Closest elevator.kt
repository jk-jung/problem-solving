import kotlin.math.*
fun elevator(l: Int, r: Int, call: Int): String {
  return if(abs(l - call) >= abs(r - call)) "right" else "left"
}