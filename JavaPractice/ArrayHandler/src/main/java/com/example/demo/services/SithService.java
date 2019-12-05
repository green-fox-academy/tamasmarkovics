package com.example.demo.services;

import com.example.demo.models.DTOs.SithRequestDTO;
import com.example.demo.models.DTOs.SithResponseOTD;
import org.springframework.stereotype.Service;

@Service
public class SithService {

    public SithResponseOTD sithResponse(SithRequestDTO sentence) {
        if (sentence != null) {
            StringBuilder returnString = new StringBuilder();
            String[] sarray = sentence.getText().split("[ .]");
            for (int i = 1; i < sarray.length; i += 2) {
                returnString.append(sarray[i]).append(" ").append(sarray[i - 1]).append(" ");
            }

            return new SithResponseOTD(returnString.toString());
        } else {
            throw new IllegalArgumentException("Feed me some text you have to, padawan young you are. Hmmm.");
        }
    }
}
