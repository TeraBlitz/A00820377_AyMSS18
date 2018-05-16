import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MateriasPrimasItemComponent } from './materias-primas-item.component';

describe('MateriasPrimasItemComponent', () => {
  let component: MateriasPrimasItemComponent;
  let fixture: ComponentFixture<MateriasPrimasItemComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MateriasPrimasItemComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MateriasPrimasItemComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
