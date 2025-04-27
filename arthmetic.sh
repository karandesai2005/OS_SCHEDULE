#/bin/bash
echo "enter num1: "
read num1
echo "enter num2"
read num2

echo "Addition $((num1 + num2))"
echo "Subtraction $((num1 - num2))"
echo "multiplication $((num1*num2))"

if [$num2 -eq 0]; then
  echo "division errro "

else
  echo "dvision $(echo "scale =20; $num1/$num2" |bc)"
fi
