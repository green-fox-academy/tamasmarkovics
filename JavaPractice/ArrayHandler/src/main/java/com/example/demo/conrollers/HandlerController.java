package com.example.demo.conrollers;

import com.example.demo.models.DTOs.ErrorDTO;
import com.example.demo.models.DTOs.RequestDTO;
import com.example.demo.models.DTOs.SithErrorDTO;
import com.example.demo.models.DTOs.SithRequestDTO;
import com.example.demo.services.HandlerService;
import com.example.demo.services.LoggingService;
import com.example.demo.services.SithService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.Arrays;

@RestController
public class HandlerController {
    private HandlerService handlerService;
    private LoggingService loggingService;
    private SithService sithService;

    @Autowired
    public HandlerController(HandlerService handlerService, LoggingService loggingService, SithService sithService) {
        this.handlerService = handlerService;
        this.loggingService = loggingService;
        this.sithService = sithService;
    }


    @PostMapping(value = "/arrays")
    public ResponseEntity arrayController(@RequestBody(required = false) RequestDTO data) {
        try {
            this.loggingService.save(data.getWhat(), Arrays.toString(data.getNumbers()));
            return ResponseEntity.status(HttpStatus.OK).body(handlerService.arrayHandler(data));
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.OK).body(new ErrorDTO(e.getMessage()));
        }
    }

    @PostMapping(value = "/sith")
    public ResponseEntity sithController(@RequestBody(required = false) SithRequestDTO sithRequestDTO) {
        try {
            return ResponseEntity.status(HttpStatus.OK).body(sithService.sithResponse(sithRequestDTO));
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.OK).body(new SithErrorDTO(e.getMessage()));
        }
    }


}
