package com.example.demo.services;

import com.example.demo.models.DTOs.ArrayResponseDTO;
import com.example.demo.models.DTOs.RequestDTO;
import com.example.demo.models.DTOs.IntResponseDTO;
import com.example.demo.models.DTOs.ResponseDTO;
import org.springframework.stereotype.Service;

import java.util.Arrays;

@Service
public class HandlerService {

    public IntResponseDTO sum(int[] array) {
        return new IntResponseDTO(Arrays.stream(array).sum());
    }

    public IntResponseDTO multiply(int[] array) {
        int multi = 1;
        for (int i : array) {
            multi *= i;
        }
        return new IntResponseDTO(multi);
    }

    public ArrayResponseDTO doubler(int[] array) {
        for (int i = 0; i < array.length; i++) {
            array[i] *= 2;
        }
        return new ArrayResponseDTO(array);
    }

    public ResponseDTO arrayHandler(RequestDTO data) {
        switch (data.getWhat()) {
            case "multiply":
                return multiply(data.getNumbers());
            case "sum":
                return sum(data.getNumbers());
            case "double":
                return doubler(data.getNumbers());
            default:
                throw new IllegalArgumentException("Please provide what to do with the numbers!");
        }
    }
}
