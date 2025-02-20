# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_nums.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdaniely <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 13:32:47 by vdaniely          #+#    #+#              #
#    Updated: 2025/02/14 17:41:28 by vdaniely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

import random
import os
import subprocess

amount_ints = 20
"""
with open('randoms.env', 'w') as file:
  file.write('export ARG="')
  for i, elem in enumerate(random.sample(range(-2**31, 2**31), amount_ints)):
    if i == amount_ints - 1:
      file.write(str(elem))
      continue
    file.write(str(elem) + ' ')
  file.write('"')
"""
"""
with open('random_ints.env', 'w') as file:
  file.write('export ARG="')
  for j in range(500):
    if j == 499:
      file.write(str(random.randint(0, 9)))
      break
    file.write(str(random.randint(0, 9)) + ' ')
  file.write('"')
"""

with open('randoms_pos.env', 'w') as file:
  file.write('export ARG="')
  for i, elem in enumerate(random.sample(range(0, 2**31), amount_ints)):
    if i == amount_ints - 1:
      file.write(str(elem))
      continue
    file.write(str(elem) + ' ')
  file.write('"')

